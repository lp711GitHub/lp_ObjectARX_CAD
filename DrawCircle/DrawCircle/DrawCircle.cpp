#include "StdAfx.h"
#include "resource.h"
#include "dbents.h"

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
	
	// 获得指向块表的指针
	AcDbBlockTable *pBlockTable; 
	acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBlockTable, AcDb::kForRead);

	// 获得指向特定的块表记录（模型空间）的指针
	AcDbBlockTableRecord *pBlockTableRecord; 
	pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord, AcDb::kForWrite);

	// 将AcDbLine类的对象添加到块表记录中
	AcDbObjectId circleId; 
	pBlockTableRecord->appendAcDbEntity(circleId, circle);

	// 关闭图形数据库的各种对象
	pBlockTable->close(); 
	pBlockTableRecord->close(); 
	circle->close();
} 

void initApp() 
{
// 注册新的命令
	acedRegCmds->addCommand(_T("Cmd_Group"), 
	_T("DrawCircle"), 
	_T("DrawCircle "), 
	ACRX_CMD_TRANSPARENT, 
	DrawCircle); 
} 
void unloadApp() 
{ 
	acedRegCmds->removeGroup(_T("Cmd_Group ")); 
} 

//程序入口函数
extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void* pkt) 
{ 
	switch (msg) 
	{ 
	case AcRx::kInitAppMsg: 
		//是否允许程序被卸载。 
		acrxDynamicLinker->unlockApplication(pkt); 
		//决定该程序是否支持多文档。 
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
