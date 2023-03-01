#include "StdAfx.h"
#include "Calculate.h"

Calculate::Calculate(void)
	{
	}

Calculate::~Calculate(void)
	{
	}

double Calculate::Max(double a,double b){
	if (a > b) 
	 { 
		return a; 
	 } 
	 else 
	 { 
		return b; 
	 }
}

double Calculate::Min(double a, double b) 
{ 
	 if (a < b) 
	 { 
		return a; 
	 } 
	 else 
	 { 
		return b; 
	 } 
}