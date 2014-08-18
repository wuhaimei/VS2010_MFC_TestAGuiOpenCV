
// TestOpevCvDlg.h : 头文件
//

#pragma once

#include "AGuiOpenCV244.h"
#include "AGuiOpenAI.h"


// CTestOpevCvDlg 对话框
class CTestOpevCvDlg : public CDialogEx
{
// 构造
public:
	CTestOpevCvDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TESTOPEVCV_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

private:
	IplImage*   m_ImgSrc;
	IplImage*   m_ImgRes;


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnDestroy();

	afx_msg void OnOpenImgFile();
	afx_msg void OnSaveImgFile();
	afx_msg void OnImgReverse();
	afx_msg void OnImgLine();
	afx_msg void OnImgLineSub();
	afx_msg void OnImgThres();
	afx_msg void OnImgFilterAve();
	afx_msg void OnImgFilterMedia();
	afx_msg void OnImgFilterGauss();
	afx_msg void OnImgFilterHistog();
	afx_msg void OnImgFilterThres();
	afx_msg void OnImgCAveEZ();
	afx_msg void OnImgSharpenLaplace();
	afx_msg void OnSharpenRobert();
	afx_msg void OnSharpenSobel();
	afx_msg void OnImgSharpenGrad();
	afx_msg void OnImgZoomNearest();
	afx_msg void OnImgZoomDBLine();
	afx_msg void OnImgZoomHLevel();
	afx_msg void OnImgMirrorLR();
	afx_msg void OnImgMirrorUD();
	afx_msg void OnImgMove();
	afx_msg void OnImgRotation();
	afx_msg void OnImgTranspos();
	afx_msg void OnImgBuggle();
	afx_msg void OnImgSunken();
	afx_msg void OnImgLadder();
	afx_msg void OnImgDWT();
	afx_msg void OnImgIDWT();

};
