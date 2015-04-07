#pragma once

#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osgViewer\api\Win32/GraphicsWindowWin32>
#include <osgGA/TrackballManipulator>
#include <osgEarth/MapNode>
#include <osgEarthUtil/EarthManipulator>
#include <osgEarthUtil/Sky>
#include <osgEarth/ImageLayer>
#include "3DSmartCity.h"
#include "PipeStatisticHandler.h"
#include "HeadFiles.h"
#include "AddPipe.h"
#include "AddFlagDlg.h"
#include "AddClick.h"
#include "CSection.h"
#include "FlowDirectionDialog.h"
#include "VSection.h"

using namespace osgEarth;
class COSGObject
{
public:
	COSGObject(HWND hWnd);
	~COSGObject(void);
	void InitOSG();
	void InitSceneGraph();
	void InitCameraConfig();//初始化相机
	void PreFrameUpdate();//前处理
	void PostFrameUpdate();//后处理
	static void Render(void * ptr);//规避线程互斥方法
	osg::ref_ptr<osgEarth::MapNode> mapNode;
	vector<string> layernames;
	osgEarth::ImageLayerVector imageLayerVec;

	osgViewer::Viewer *getViewer();
	void InitOsgEarth();
	void setChinaBoundariesOpacity(double opt);
	double getChinaBoundariesOpacity();
	void rmvChinaBounds();
	void addChinaBounds();

	void addPipe(string pipeName,string pointName);


	//biaohui--mark
	CAddFlagDlg *addlg;
	bool closeWindows;
	void addFlag();	
	osg::ref_ptr<osg::Group> mLabels;

	//画线启用标志 横断面分析;--songweiwang
	bool isDrawLineStart;
	osg::ref_ptr<osg::Group> mCSLine;
	//---end hengduanfenxi

	//纵断面分析---songweiwang;	
	bool isVsectionStart;	

	//---end zongduanfenxi

	//dc--管线统计-----------------------------------------------------------------
public:
	bool ifDoStatistic;
	StatisticDialog* pStatisticDlg;
	void initStatisticDlg();
	osg::Group* pRectNodeGroup;
	//dc----------------------------------------------------------------------------

	//dc--流向分析------------------------------------------------------------------
	FlowDirectionDialog* pFlowDirectionDlg;
	void initFlowDirectionDlg();
	//dc----------------------------------------------------------------------------

	//------wangsongwei  加上模型层控制
	ModelLayerVector modelLayerVec;
	osg::ref_ptr<osg::Group> mPipeGroup;


private:
	HWND n_hWnd;//创建一个句柄
	osgViewer::Viewer * mViewer;
	osg::ref_ptr<osg::Group> mRoot;

	osg::ref_ptr<osgEarth::Util::EarthManipulator> em;
	osg::ref_ptr<osgEarth::ImageLayer> china_boundaries;
	//管线 管点
private:
	map<string ,string> *pipes;
public:
	void pipeView(void);
	void buildingView(void);

};


