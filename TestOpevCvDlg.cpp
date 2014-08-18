
// TestOpevCvDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TestOpevCv.h"
#include "TestOpevCvDlg.h"
#include "afxdialogex.h"
#include "AGuiPath.h"
#include "CvvImage.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestOpevCvDlg �Ի���




CTestOpevCvDlg::CTestOpevCvDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestOpevCvDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_ImgSrc=NULL;
	m_ImgRes=NULL;
}

void CTestOpevCvDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestOpevCvDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_OPEN, OnOpenImgFile)
	ON_COMMAND(ID_SAVE, OnSaveImgFile)
	ON_COMMAND(ID_REVERSE, OnImgReverse)
	ON_COMMAND(ID_LINE, OnImgLine)
	ON_COMMAND(ID_LINESUB, OnImgLineSub)
	ON_COMMAND(ID_THRES, OnImgThres)
	ON_COMMAND(ID_FILTER_AVE, OnImgFilterAve)
	ON_COMMAND(ID_FILTER_MEDIA, OnImgFilterMedia)
	ON_COMMAND(ID_FILTER_GAUSS, OnImgFilterGauss)
	ON_COMMAND(ID_FILTER_HISTOG, OnImgFilterHistog)
	ON_COMMAND(ID_FILTER_THRES, OnImgFilterThres)
	ON_COMMAND(ID_CAVEEZ,OnImgCAveEZ)
	ON_COMMAND(ID_LAPLACE,OnImgSharpenLaplace)
	ON_COMMAND(ID_ROBERT,OnSharpenRobert)
	ON_COMMAND(ID_SOBEL,OnSharpenSobel)
	ON_COMMAND(ID_GRAD,OnImgSharpenGrad)
	ON_COMMAND(ID_ZOOM_NEAREST,OnImgZoomNearest)
	ON_COMMAND(ID_ZOOM_DBLINE,OnImgZoomDBLine)
	ON_COMMAND(ID_ZOOM_HLEVEL,OnImgZoomHLevel)
	ON_COMMAND(ID_MIRROR_LR,OnImgMirrorLR)
	ON_COMMAND(ID_MIRROR_UD,OnImgMirrorUD)
	ON_COMMAND(ID_MOVE,OnImgMove)
	ON_COMMAND(ID_ROTATION,OnImgRotation)
	ON_COMMAND(ID_TRANSPOS,OnImgTranspos)
	ON_COMMAND(ID_BUGGLE,OnImgBuggle)
	ON_COMMAND(ID_SUNKEN,OnImgSunken)
	ON_COMMAND(ID_LADDER,OnImgLadder)

	ON_COMMAND(ID_DWT,OnImgDWT)
	ON_COMMAND(ID_IDWT,OnImgIDWT)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CTestOpevCvDlg ��Ϣ�������

BOOL CTestOpevCvDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	//CString strPathName="";
	//strPathName.Format("%sface\\Lena_Noise.jpg",GetParentDir());//Lena_Noise  lena
	//IplImage *src  = LoadImage(strPathName);
	//IplImage *res=NULL;
	//res = ReverseImage(src);
	//res = Linear(src,2,-90);
	//res = SubLinear(src,50,150,150,255);
	//res = Threshold(src,100,200);
	//res = EnchanceAve(src);
	//res = EnchanceGaus(src);
	//res = EnchanceHistog(src);
	//res = EnchanceMedian(src);
	//res = EnchanceThres(src);

	/*ShowFadein(src);
	ShowLeftTopLine(src);
	ShowLeftRight(src);
	ShowMidCircle(src);
	ShowMidRect(src);
	ShowUpDown(src);
	ShowUpDownMove(src);
	ShowUpLeft(src);*/

	//ShowWaitKey(src,res);
	//ShowWaitKey(src,"ԭͼ");
	//ShowWaitKey(res,"��ת���");

	//ReleaseImage(&src);
	//ReleaseImage(&res);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTestOpevCvDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTestOpevCvDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();

		if(m_ImgSrc)
		{
			DrawImgToPicCtrl(m_ImgSrc,this,IDC_STATIC_IMG_SRC,TRUE);
		}
		if(m_ImgRes)
		{
			DrawImgToPicCtrl(m_ImgRes,this,IDC_STATIC_IMG_RES,TRUE);
		}

	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTestOpevCvDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTestOpevCvDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	if(m_ImgSrc)
	{
		ReleaseImage(&m_ImgSrc);
		m_ImgSrc=NULL;
	}
	if(m_ImgRes)
	{
		ReleaseImage(&m_ImgRes);
		m_ImgRes=NULL;
	}
}

void CTestOpevCvDlg::OnOpenImgFile()
{
	if(m_ImgSrc)
	{
		ReleaseImage(&m_ImgSrc);
		m_ImgSrc=NULL;
	}
	CString strPathName="";
	CFileDialog FileOpenDlg(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"�����ļ�(*.*)|*.*|bmp|*.bmp|jpg|*.jpg||", this);
	if (FileOpenDlg.DoModal() !=IDOK )
	{
		return;
	}
	strPathName = FileOpenDlg.GetPathName();   //strPathName.Format("%sface\\Lena_Noise.jpg",GetParentDir());//Lena_Noise  lena
	m_ImgSrc  = LoadImage(strPathName);
	Invalidate();
}

void CTestOpevCvDlg::OnSaveImgFile()
{
	if(!m_ImgRes)
	{
		return;
	}
	CString strPathName="";
	CFileDialog FileOpenDlg(FALSE,".jpg",NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"jpg|*.jpg|bmp|*.bmp|png|*.png||", this);
	if (FileOpenDlg.DoModal() !=IDOK )
	{
		return;
	}
	strPathName = FileOpenDlg.GetPathName();
	cvSaveImage(strPathName,m_ImgRes);
}
void CTestOpevCvDlg::OnImgReverse()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = ReverseImage(m_ImgSrc);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnImgLine()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = Linear(m_ImgSrc,2,-90);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnImgLineSub()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = SubLinear(m_ImgSrc,50,50,150,255);
		Invalidate();
	}
}

void CTestOpevCvDlg::OnImgThres()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = Threshold(m_ImgSrc,100,200);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnImgFilterAve()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes =  EnchanceAve(m_ImgSrc);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnImgFilterMedia()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = EnchanceMedian(m_ImgSrc);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnImgFilterGauss()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = EnchanceGaus(m_ImgSrc);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnImgFilterHistog()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = EnchanceHistog(m_ImgSrc);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnImgFilterThres()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = EnchanceThres(m_ImgSrc);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnImgCAveEZ()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = CAveErZhi(m_ImgSrc);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnImgSharpenLaplace()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = SharpenLaplace(m_ImgSrc);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnSharpenRobert()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = SharpenRobert(m_ImgSrc);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnSharpenSobel()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = SharpenSobel(m_ImgSrc);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnImgSharpenGrad()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = SharpenGrad(m_ImgSrc);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnImgZoomNearest()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = ZoomNearest(m_ImgSrc,5,5);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnImgZoomDBLine()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = ZoomDBLine(m_ImgSrc,5,5);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnImgZoomHLevel()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = ZoomHLevel(m_ImgSrc,5,5);
		Invalidate();
	}
}

void CTestOpevCvDlg::OnImgMirrorLR()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = GeoMirrorLeftRight(m_ImgSrc);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnImgMirrorUD()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = GeoMirrorUpDown(m_ImgSrc);
		Invalidate();
	}
}
 void CTestOpevCvDlg::OnImgMove()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = GeoMove(m_ImgSrc,50,50);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnImgRotation()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = GeoRotate(m_ImgSrc,90);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnImgTranspos()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = GeoTransPose(m_ImgSrc);
		Invalidate();
	}
}

void CTestOpevCvDlg::OnImgBuggle()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = GeoHaBuggle(m_ImgSrc,Buggle_Sin);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnImgSunken()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = GeoHaSunken(m_ImgSrc,Sunken_Sin);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnImgLadder()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = GeoHaLadder(m_ImgSrc,1.0/3,2.0/3,0,1);
		Invalidate();
	}
}

void CTestOpevCvDlg::OnImgDWT()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = TransDWT(m_ImgSrc,1);
		Invalidate();
	}
}
void CTestOpevCvDlg::OnImgIDWT()
{
	if(m_ImgSrc)
	{
		if(m_ImgRes)
		{
			ReleaseImage(&m_ImgRes);
			m_ImgRes=NULL;
		}
		m_ImgRes = TransIDWT(m_ImgSrc,1);
		Invalidate();
	}
}