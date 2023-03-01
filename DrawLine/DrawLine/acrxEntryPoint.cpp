#include "stdafx.h" 
#include "dbents.h"
#include "Calculate.h"
#include "dbelipse.h"
#include "string"
using namespace std;

//将对象放入实体空间
AcDbObjectId PostToModelSpace(AcDbEntity* pEnt) 
{ 
	 AcDbBlockTable *pBlockTable; 
	 acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBlockTable, AcDb::kForRead); 
	 AcDbBlockTableRecord *pBlockTableRecord; 
	 pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord, AcDb::kForWrite); 

	 AcDbObjectId entId; 
	 pBlockTableRecord->appendAcDbEntity(entId, pEnt); 

	 pBlockTable->close(); 
	 pBlockTableRecord->close(); 
	 pEnt->close(); 

	 return entId; 
}

//移动实体
Acad::ErrorStatus Move(AcDbObjectId entId, const AcGePoint3d &ptFrom, const AcGePoint3d &ptTo) 
{ 
	// 构建用于实现移动实体的矩阵
	 AcGeVector3d vec(ptTo[X] - ptFrom[X], ptTo[Y] - ptFrom[Y], ptTo[Z] - ptFrom[Z]); 
	 AcGeMatrix3d mat; 
	 mat.setToTranslation(vec); 
	 AcDbEntity *pEnt = NULL; 
	 Acad::ErrorStatus es = acdbOpenObject(pEnt, entId,AcDb::kForWrite); 
	if (es != Acad::eOk) 
		return es; 
	es = pEnt->transformBy(mat); 
	pEnt->close(); 
	return es; 
}

//复制实体
BOOL Copy(AcDbObjectId entId, const AcGePoint3d &ptFrom, const AcGePoint3d &ptTo) 
{ 
	 AcDbEntity *pEnt = NULL; 
	 if (acdbOpenObject(pEnt, entId, AcDb::kForRead) != Acad::eOk) 
		return FALSE; 
	 AcDbEntity *pCopyEnt = AcDbEntity::cast(pEnt->clone()); 
	 AcDbObjectId copyEntId ; 
	 if (pCopyEnt) 
		copyEntId = PostToModelSpace(pCopyEnt); 
	 Move(copyEntId, ptFrom, ptTo); 
	 return TRUE; 
}

//画直线
void DrawLine ()
{
	AcGePoint3d ptStart(0, 0, 0); 
	AcGePoint3d ptEnd(100, 100, 0); 

	AcGePoint3d ptFrom_move(100,0,0);
	AcGePoint3d ptTo_move(200,100,0);

	AcGePoint3d ptFrom_copy(200,100,0);
	AcGePoint3d ptTo_copy(300,100,0);

	AcDbLine *pLine = new AcDbLine(ptStart, ptEnd);

	AcDbObjectId lineId = PostToModelSpace(pLine);;

	//调用移动和拷贝函数
	Move(lineId,ptFrom_move,ptTo_move);
	Copy(lineId,ptFrom_copy,ptTo_copy);
} 

//画圆
void DrawCircle ()
{
	//构造函数
	//AcDbCircle(const AcGePoint3d& cntr, const AcGeVector3d& nrm, double radius);
	
	//圆的参数
	AcGePoint3d cntr(50,50,50);	//圆心
	AcGeVector3d nrm(0,0,1);		//所在平面
	double radius = 10.0;					//半径
	AcDbCircle *circle = new AcDbCircle(cntr, nrm,radius);
	
	PostToModelSpace(circle);
} 
//画圆弧
void DrawArc ()
{
	//构造函数
	//AcDbArc( const AcGePoint3d& center, double radius, double startAngle, double endAngle);
	AcGePoint3d center(0,0,0);
	double radius = 20.0;
	double startAngle = 1.0;
	double endAngle = 2.0;
	AcDbArc *arc = new AcDbArc(center,radius,startAngle,endAngle);

	PostToModelSpace(arc);
} 
//画多条线
void DrawMulLine ()
{	
	AcGePoint3d pt1(10, 10, 10), pt2(10, 50, 35), pt3(100, 100, 0); 
	 AcGePoint3dArray points;	//点的数组
	 points.append(pt1); 
	 points.append(pt2); 
	 points.append(pt3);

	AcDb3dPolyline *pPoly3d = new AcDb3dPolyline(AcDb::k3dSimplePoly, points);
	PostToModelSpace(pPoly3d);
} 

//画矩形
void DrawRetang ()
{
	//构造函数
	//AcDbCircle(const AcGePoint3d& cntr, const AcGeVector3d& nrm, double radius);
	
	AcGePoint2d pt1(60,70);
	AcGePoint2d pt2(100,100);

	// 提取两个角点的坐标值
	double x1 = pt1.x, x2 = pt2.x; 
	double y1 = pt1.y, y2 = pt2.y; 
	// 计算矩形的角点
	AcGePoint2d ptLeftBottom(Calculate::Min(x1, x2), Calculate::Min(y1, y2)); 
	 AcGePoint2d ptRightBottom(Calculate::Max(x1, x2), Calculate::Min(y1, y2)); 
	 AcGePoint2d ptRightTop(Calculate::Max(x1, x2),Calculate::Max(y1, y2)); 
	 AcGePoint2d ptLeftTop(Calculate::Min(x1, x2), Calculate::Max(y1, y2));
	// 创建对应的多段线
	AcDbPolyline *pPoly = new AcDbPolyline(4); 
	pPoly->addVertexAt(0, ptLeftBottom, 0, 1, 1); 
	pPoly->addVertexAt(1, ptRightBottom, 0,1, 1); 
	pPoly->addVertexAt(2, ptRightTop, 0, 1, 1); 
	pPoly->addVertexAt(3, ptLeftTop, 0, 1, 1); 
	pPoly->setClosed(Adesk::kTrue);
	
	PostToModelSpace(pPoly);
} 

//画椭圆
void DrawElliptic()
{
	AcGePoint3d ptCenter(70,12,70);	//椭圆心
	AcGeVector3d vecNormal(0,0,1);	//所在平面
	AcGeVector3d majorAxis(43,0,0);		//长轴矢量
	double ratio = 0.35;
	AcDbEllipse *pEllipse = new AcDbEllipse(ptCenter, vecNormal, majorAxis, ratio);

	PostToModelSpace(pEllipse);
}
//画样条曲线
void DrawSpline()
{
	AcGePoint3d pt1(13, 23, 0), pt2(19, 25, 0), pt3(27, 20, 0), pt4(34, 23, 0),pt5(35, 26.5, 0); 
	 AcGePoint3dArray points;		//曲线的拟合点数组
	 points.append(pt1); 
	 points.append(pt2); 
	 points.append(pt3); 
	 points.append(pt4);
	 points.append(pt5);

	int order = 4;	//拟合曲线的阶数
	double fitTolerance = 0.0;	//允许的拟合误差

	assert (order >= 2 && order <= 26);
	AcDbSpline *pSpline = new AcDbSpline(points, order, fitTolerance);

	PostToModelSpace(pSpline);
}
void initApp() 
{
// 注册新的命令
	string command[]={"DrawLine","DrawCircle","DrawArc","DrawMulLine","DrawRetang","DrawElliptic","DrawSpline"};
	for(int i=0;i<10;i++){
			switch(i)
			{
				case 1:
					acedRegCmds->addCommand(_T("Cmd_Group"), _T("DrawLine"), _T("DrawLine "), ACRX_CMD_TRANSPARENT, DrawLine); 
					break;
				case 2:
					acedRegCmds->addCommand(_T("Cmd_Group"), _T("DrawCircle"), _T("DrawCircle "), ACRX_CMD_TRANSPARENT, DrawCircle); 
					break;
				case 3:
					acedRegCmds->addCommand(_T("Cmd_Group"), _T("DrawArc"), _T("DrawArc "), ACRX_CMD_TRANSPARENT, DrawArc); 
					break;
				case 4:
					acedRegCmds->addCommand(_T("Cmd_Group"), _T("DrawMulLine"), _T("DrawMulLine "), ACRX_CMD_TRANSPARENT, DrawMulLine); 
					break;
				case 5:
					acedRegCmds->addCommand(_T("Cmd_Group"), _T("DrawRetang"), _T("DrawRetang "), ACRX_CMD_TRANSPARENT, DrawRetang); 
					break;
				case 6:
					acedRegCmds->addCommand(_T("Cmd_Group"), _T("DrawElliptic"), _T("DrawElliptic "), ACRX_CMD_TRANSPARENT, DrawElliptic); 
					break;
				case 7:
					acedRegCmds->addCommand(_T("Cmd_Group"), _T("DrawSpline"), _T("DrawSpline "), ACRX_CMD_TRANSPARENT, DrawSpline); 
					break;
				default:
					break;
			}
	}
} 
void unloadApp() 
{ 
	acedRegCmds->removeGroup(_T("Cmd_Group ")); 
	//acedRegCmds->removectmd(_T("Cmd_Group"),_T("HelloARX")); 
} 

//程序入口函数
extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void* pkt) 
{ 
	switch (msg) 
	{ 
	case AcRx::kInitAppMsg: 
		//是否允许程序被卸载?
		acrxDynamicLinker->unlockApplication(pkt); 
		//决定该程序是否支持多文档?
		acrxRegisterAppMDIAware(pkt); 
		initApp(); 
		break; 
	case AcRx::kUnloadAppMsg: 
		unloadApp(); 
		break; 
	default: 
		break; 
	} 
	return AcRx::kRetOK; 
}