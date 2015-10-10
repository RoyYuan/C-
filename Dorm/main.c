//头文件
#include <stdlib.h>
#include <gtk/gtk.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
/*-------------------------------------------*/

//结构体类
//登陆结构体
typedef struct Login
{
    //登陆窗口
    GtkWidget *window;
    //用户名
    GtkWidget *user;
    //密码
    GtkWidget *password;
    //验证码
    GtkWidget *identify_code;
    gchar *captcha;
    //状态值
    gint flag;
    gint errortime;
    //提示信息对话窗
    GtkWidget *dialog;
    //提示信息返回值
    gint result;
}LOGIN;

//菜单结构体
typedef struct Menu
{
    //菜单窗口
    GtkWidget *window;
    //进入信息概览时的选择楼号窗口
    GtkWidget *To_Overview_Window;
    //概览信息文件名
    gchar filename[30];
}MENU;

//退出结构体
typedef struct Quit
{
    GtkWidget *dialog;//提示对话框
    gint result;//对话框返回值
}QUIT;

//概览结构体
typedef struct Overview
{
    //窗口
    GtkWidget *window;
    //分栏列表
    GtkWidget *clist;
    int flag;
}OVERVIEW;

//添加信息结构体
typedef struct Addimf
{
    //选择楼号的窗口
    GtkWidget *choose_window;
    //大致信息填充的窗口
    GtkWidget *over_window;
    //成员信息补充的窗口
    GtkWidget *member_window;
    //大致信息填充时退出对话框
    GtkWidget *over_quit_window;
    //成员信息填充时退出对话框
    GtkWidget *stu_quit_window;
    //获取返回信息
    gint result;
    //所选楼号
    gint number;
    //存储成功提示窗
    GtkWidget *Success;
    //存储失败弹窗
    GtkWidget *Error;
}ADD;

//添加宿舍大致信息结构体
typedef struct Addoverimf
{
    GtkWidget *num;
    GtkWidget *captain;
    GtkWidget *num_people;
    GtkWidget *num_wrong_dialog;
}ADDOVERIMF;

//查找结构体
typedef struct SearchView
{
    //主窗口
    GtkWidget* choose_menu_window;
    //选择宿舍窗口
    GtkWidget* choose_dorm_window;
    //宿舍结果显示窗口
    GtkWidget* dorm_window;
    //选择学生窗口
    GtkWidget* choose_stu_window;
   //学生结果显示窗口
    GtkWidget* stu_window;
    GtkWidget* clist;
}SEARCHVIEW;

//查询参数结构体
typedef struct SearchParameter
{
    //选择查询宿舍还是学生
    gboolean dorm_or_stu;
    //选择宿舍查询楼栋
    int num_dorm;
    //选择宿舍查询宿舍号
    GtkWidget* dorm_number;
    //选择学生查询学生姓名
    GtkWidget* stu_name;
}
SEARCHPARAMETER;

//信息修改结构体
typedef struct  Revise
{
    //选择菜单窗口
    GtkWidget* choose_menu_window;
    //宿舍信息获取窗口
    GtkWidget* dorm_get_window;
    //宿舍号
    GtkWidget* dorm_num;
    //确认宿舍窗口
    GtkWidget* dorm_check_dialog;
    //修改宿舍信息窗口
    GtkWidget*dorm_revise_window;
    //学生信息获取窗口
    GtkWidget* stu_get_window;
    //学生姓名
    GtkWidget* stu_name;
    //确认学生弹窗
    GtkWidget* stu_check_dialog;
    //修改成功弹窗
    GtkWidget*success_dialog;
    //人数错误弹窗
    GtkWidget*dorm_num_wrong_window;
    //进一步获取成员信息的窗口
    GtkWidget*dorm_stu_window;
}REVISE;

//信息修改参数结构体
typedef struct  Revise_Imf
{
    //修改宿舍还是学生
    gboolean dorm_or_stu;
    //选择宿舍查询楼号
    int num_dorm;
    //宿舍号
    gchar dorm_number[4];
    //学生姓名
    gchar stu_name[30];
    //文件名
    gchar datafile[30];
    gchar overfile[30];
    //宿舍人数
    gchar num_people;
    //data修改指针
    struct Linklist*datap,*dorm_head;
    //overview修改地址
    struct Ddata*overviewp,*overview_head;
} REVISE_IMF;

//学生详细信息窗口
typedef struct Stu_Info
{
    //姓名
    GtkWidget *name;
    //班级
    GtkWidget *classes;
    //电话
    GtkWidget *tel;
    //父母姓名
    GtkWidget *parent_name;
    //父母电话
    GtkWidget *parent_tel;
    //当前录入的学生数
    int addimf_stu_num;
}STU_INFO;

//登陆账号密码结构体
typedef struct Sdata
{
    char user[30];//用户名
    char password[30];//用户密码
    struct Sdata *next;
}SDATA;

//宿舍概览结构体
typedef struct Ddata
{
    //宿舍号
    char num[4];
    //舍长名
    char captain[30];
    //成员名
    char member[6][30];
    struct  Ddata *next;
}DDATA;

//成员详细信息结构体
typedef struct Stu_Imf
{
    //姓名
    char name[30];
    //性别
    gboolean   sex;
    //班级
    char classes[30];
    //电话
    char tel[30];
    //家长姓名
    char parent_name[30];
    //家长电话
    char parent_tel[30];
}STU_IMF;

//宿舍详细信息结构体
typedef struct D_Imf
{
    //宿舍号
    char num[4];
    //舍长名
    char    captain[30];
    //宿舍人数
    char num_people;
    //成员信息
    STU_IMF member[6];
}D_IMF;

//链表
typedef struct  Linklist
{
    //信息数据
    D_IMF dormitory;
    //下一个结点
    struct Linklist *next;
    //上一个结点
    struct Linklist *last;
} LINKLIST;

//修改宿舍信息参数结构体
typedef struct Dormwidget
{
    GtkWidget* captain;
    GtkWidget* num;
}DORMWIDGET;

//声明需要用地址的几个值
int return_num[7]={0,1,2,3,4,5,6};
//声明双向链表头,指针
LINKLIST *head1,*p1;
//学生信息
STU_IMF *stu_search[30];
//声明登陆部分结构体
LOGIN login;
//声明菜单结构体
MENU menu;
//声明退出键结构体
QUIT quit;
//声明概览结构体
OVERVIEW overview;
//声明添加信息结构体
ADD add;
//声明宿舍大致信息结构体
D_IMF d_imf;
//声明宿舍成员具体信息
STU_IMF stu_imf;
//声明添加宿舍大致信息结构体
ADDOVERIMF Addoverimf;
//声明学生详细信息窗口结构体
STU_INFO stu_info;
//声明概览性数据结构体
DDATA ddata;
//声明查询结构体
SEARCHVIEW searchview ;
//声明查询参数结构体
SEARCHPARAMETER searchparameter;
//声明修改结构体
REVISE  revise;
//声明修改参数结构体
REVISE_IMF revise_imf;
//声明修改临时寄存结构体
D_IMF   dorm_temp;
//声明修改宿舍参数结构体
DORMWIDGET dormwidget;
//声明修改宿舍参数结构体
STU_INFO dorm_stu;
DDATA   dorm_stu_temp;

/*-------------------------------------------*/

//创建类函数//
//窗口创建函数
gpointer Create_Window(GtkWindowType,gchar*,gint,gint,gboolean);
//输入文本框创建函数
gpointer Create_Entry(gint, gboolean, gboolean);
//图标获取函数
GdkPixbuf  *Create_Pixbuf(const gchar*);
//4位验证码随机生成函数
gchar* Captcha_Create();
//创建链表从文件中读取信息
LINKLIST* Create_Linklist(char* datafile);

/*-------------------------------------------*/

//mod类函数//
//宿舍文件读取
struct Ddata *Read_Ddata();
//宿舍排序
DDATA *Sort_Ddata(DDATA *,int);

/*-------------------------------------------*/

//窗口类函数//
//登陆
void Login_View();
//用户不存在对话框
void Login_Username_Wrong();
//密码错误对话框
void Login_Password_Wrong();
//密码错误超过3次对话框
void Login_Error();
//验证码错误窗口
void Login_Captcha_Wrong();
//退出
gboolean Quit_View(GtkWidget*,gpointer);
//菜单
void Menu_View();
//概览
void Overview_View();
//从菜单页面到概览页面选择楼号对话窗
gchar* Menu_To_Overview(GtkWidget*,gpointer);
//添加信息窗口
void Addimf_View();
//添加宿舍大致信息窗口
void Addimf_Over_View();
//添加大致信息时人数不对警告窗口
void Addimf_Overview_Num_Wrong_View();
//添加大致信息时退出对话框
gboolean Addimf_Overview_Quit_View();
//添加学生详细信息
void Addimf_Stu_View();
//添加详细学生信息时退出对话框
gboolean Addimf_Stu_Quit_View();
//添加信息存储成功弹窗
void Addimf_Save_Success();
//添加信息存储失败弹窗
void Addimf_Save_Error();
//查询菜单窗口
void Search_Choose_Menu_View();
//查询宿舍选择窗口
void Search_Choose_Dorm_View();
//查询宿舍结果窗口
void Search_Dorm_View();
//查询学生选择窗口
void Search_Choose_Stu_View();
//查询学生结果窗口
void Search_Stu_view();
//修改菜单窗口
void Revise_Choose_View();
//修改宿舍信息录入窗口
void Revise_Dorm_Get_View();
//修改学生信息录入窗口
void Revise_Stu_Get_View();
//修改学生信息确认窗口
void Revise_Stu_Isok(GtkWidget *,gpointer);
//修改_宿舍确认窗口
void Revise_Dorm_Check_View(LINKLIST*);
//修改宿舍信息窗口
void Revise_Dorm_View(LINKLIST*);
//修改宿舍信息存储成功弹窗
void Revise_Dorm_Save_Success();

/*-------------------------------------------*/

//转换类函数
//从登陆页面转到菜单页面
void Login_To_Menu();
//从信息概览楼号选择窗口返回菜单页面
void Menu_To_Overview_Return_Menu();
//从菜单页面点击添加信息到选择楼号窗口
void Menu_To_Addimf();
//从信息添加楼号选择窗口返回菜单页面
void Addimf_Choose_Return();
//从信息添加楼号选择窗口到宿舍大致信息填写窗口
void Addimf_Choose_To_Overview();
//从添加大致宿舍信息窗口返回菜单页面
void Addimf_Overview_return();
//从添加成员信息窗口返回菜单页面
void Addimf_Stu_return();
//从菜单到查询
void Menu_To_Search();
//从查询菜单到查询
void Search_Menu_To_Search();
//宿舍菜单到宿舍结果
void Dorm_Menu_To_Dorm();
//学生菜单到学生
void Stu_Menu_To_Stu();
//从菜单到修改菜单
void Menu_To_Revise();
//从修改菜单返回菜单
void Revise_Choose_Return();
//从修改菜单到选择楼号菜单
void Revise_Menu_To_Dorm_Get();
//从修改菜单到学生信息录入窗口
void Revise_Menu_To_Stu_Get();
//从修改宿舍信息录入返回修改菜单
void Revise_Dorm_Get_Return();
//从修改学生信息录入返回修改菜单
void Revise_Stu_Get_Return();
//从宿舍信息确认窗口返回宿舍信息录入窗口
void Revise_Dorm_Check_Return();
//修改_从宿舍信息确认窗口到宿舍信息填写窗口
void Revise_Dorm_Check_To_View(GtkWidget*,gpointer);
//从查找返回菜单
void Search_Choose_Menu_Return();
//修改_从成员详细信息返回宿舍概览信息填写窗口
void Revise_Dorm_Stu_Goback();
//从搜索学生返回
void Search_Stu_Return();
//从搜索宿舍返回
void Search_Dorm_Return();
//从搜索学生的选择窗口返回
void Search_Choose_Stu_Return();
//从搜索宿舍的选择窗口返回
void Search_Choose_Dorm_Return();
//修改_从宿舍大致信息修改页面返回
void Revise_Dorm_Revise_Return();

/*-------------------------------------------*/

//控制类函数
//宿舍概览_选择列返回函数
void select_row_callback(GtkWidget *widget,gint row,gint column,GdkEventButton *event,gpointer data);
//登陆检查
void Login_Check(GtkWidget*,gpointer);
//宿舍概览_根据选择的楼号改变变量值
void Menu_To_Overview_Button_Check(GtkWidget*,gpointer);
//将所填写的大致信息存入变量
void Addimf_Overview_Save();
//信息添加_根据选择的楼号改变变量值
void Menu_To_Addimf_Button_Check(GtkWidget*,gpointer);
//详细学生信息检查
void Addimf_Stu_Check(GtkWidget *,gpointer);
//详细信息性别检查
void Stu_Sex_Button_Check(GtkWidget *,gpointer);
//控制成员信息添加中的"上一步"按钮
void Addimf_Stu_Goback();
//详细信息保存最终版
void Addimf_Stu_Save(GtkWidget *,gpointer);
//将添加信息存入data和overview文件
gboolean Addimf_Save();
//释放链表
void Linklist_Free(LINKLIST*head);
//重置d_imf全局变量
void Init_d_imf();
//查询菜单检查
void Search_Choose_Menu_Button_Check(GtkWidget *,gpointer);
//宿舍楼号检查
void Dorm_Menu_To_Search_Button_Check(GtkWidget*,gpointer);
//修改菜单检查
void Revise_Choose_Menu_Button_Check(GtkWidget * widget,gpointer data);
//从修改菜单到获取信息
void Revise_Menu_To_Get();
//修改宿舍信息录入楼号检查
void Revise_Dorm_Get_Button_Check(GtkWidget*widget,gpointer gdata);
//修改_将查询到的宿舍信息读出，并询问是否修改
void Revise_Dorm_Check();
//修改学生搜索
void Revise_Stu_To_Get();
//修改_检测宿舍修改人数
void Revise_Dorm_Num_Check();
//修改_宿舍成员信息录入检查
void Revise_Dorm_Stu_Check();
//修改_宿舍详细信息性别检查
void Revise_Dorm_Stu_Sex_Button_Check(GtkWidget *,gpointer);
//将宿舍修改信息存入data和overview文件
gboolean Revise_Dorm_Save();
//修改_在overview文件中找到需要的信息位置
DDATA* Revise_Dorm_Stu_Search(char*);
//修改_宿舍详细信息保存最终版
void Revise_Dorm_Stu_Save(GtkWidget *,gpointer);

/*-------------------------------------------*/

//创建类参数
//窗口创建函数
gpointer Create_Window(GtkWindowType type,gchar *title,gint width,gint height,gboolean resizable)
{
    GtkWidget *window;
    //创建type格式的窗口
    window=gtk_window_new(type);
    //设置窗口的标题
    gtk_window_set_title(GTK_WINDOW(window),title);
    //设置窗口的大小
    gtk_widget_set_size_request(GTK_WIDGET(window),width,height);
    //设置窗口的位置
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER_ALWAYS);
    //设置窗口的可伸缩性
    gtk_window_set_resizable(GTK_WINDOW(window),resizable);
    //图标设置
	gtk_window_set_icon(GTK_WINDOW(window),Create_Pixbuf("./title.jpg"));
    return window;
}

//输入文本框创建函数
gpointer Create_Entry(gint max, gboolean editable, gboolean visible)
{
	GtkWidget *entry;
	//创建新的文本输入框
	entry = gtk_entry_new();
	//定义最长输入字节数
    gtk_entry_set_max_length(GTK_ENTRY(entry),max);
    //定义可编辑性
	gtk_entry_set_editable(GTK_ENTRY(entry),editable);
	//定义可视性
	gtk_entry_set_visibility(GTK_ENTRY(entry),visible);
	//显示
	gtk_widget_show(entry);
	return entry;
}

//创建链表从文件中读取信息
LINKLIST* Create_Linklist(char* datafile)
{
    LINKLIST *head,*temp1,*temp2;
    int sum=0;
    //以只读形式打开文件
    FILE *fp;
    fp=fopen(datafile,"r");
    //初始化头指针
    head=(LINKLIST*)malloc(sizeof(LINKLIST));
    head->last=NULL;
    head->next=NULL;
    temp1=head;
    temp2=(LINKLIST*)malloc(sizeof(LINKLIST));
    //g_print("%s\n",datafile);
    //读取数据
    while(fread(&temp2->dormitory,sizeof(D_IMF),1,fp))
    {
        g_print("%s   %s\n",temp2->dormitory.num,temp2->dormitory.captain);
        temp1->next=temp2;
        temp2->last=temp1;
        temp2->next=NULL;
        temp1=temp2;
        temp2=(LINKLIST*)malloc(sizeof(LINKLIST));
        sum++;
    }
    //g_print("1234\n");
    temp1->next=NULL;
    //关闭文件流
    fclose(fp);
    if(sum)
    {
//        g_print("Head %d next %d\n",head,head->next);
        //返回头指针
        return (head);
    }
    else
    {
        g_print("Failed to find.\n");
        return NULL;
    }
}

//图标获取函数
GdkPixbuf  *Create_Pixbuf(const gchar*filename)
{
	GdkPixbuf *pixbuf;
	GError *error =NULL;
	//获取图标
	pixbuf=gdk_pixbuf_new_from_file(filename,&error);
	//如果pixbuf为NULL,打印错误信息
	if(!pixbuf)
	{
		fprintf(stderr,"%s\n",error->message);
		g_error_free(error);
	}
	//返回其地址
	return pixbuf;
}

//4位验证码生成函数
gchar* Captcha_Create()
{
    gint i,temp;
    gchar*captcha;
    //分配内存空间
    captcha=(gchar*)malloc(sizeof(gchar)*5);
    //初始化
    memset(captcha,0,sizeof(gchar)*5);
    //用时间做种
    srand((unsigned) time(NULL));
    //取4位随机验证码
    for(i=0;i<4;i++)
    {
        temp=rand()%26+97;
        *(captcha+i)=temp;
    }
    //返回字符串的首地址
    return captcha;
}

/*-------------------------------------------*/

//mod类函数
//宿舍数据读取
DDATA *Read_Ddata(char *file)
{
    FILE *fp;
    DDATA *head,*p,*da;
    //为头结点分配空间
    head = (DDATA*)malloc(sizeof(DDATA));
    head->next=NULL;
    p=head;
    fp=fopen(file,"r");
    //当fp为NULL时，终端打印信息
    if(!fp)
        g_print("文件打开错误\n");
    else
        g_print("文件打开成功\n");
    //分配空间
    da=(DDATA*)malloc(sizeof(DDATA));
    //将文件中数据读取到链表中
    while(fread(da, sizeof(DDATA), 1, fp) != 0)
    {
            p->next=da;
            p=da;
            da=(DDATA*)malloc(sizeof(DDATA));

//        g_print("独处%s%s%s%s%s%s%s%s\n",p->num,p->captain,p->member[0],p->member[1],p->member[2],p->member[3],p->member[4]);
    }
    p->next=NULL;
    //关闭文件流
    fclose(fp);
    return head;
}

//宿舍排序
DDATA *Sort_Ddata(DDATA *head,int flag)
{
    DDATA *temp,*q,*p;
    //从链表头开始,往后找
    for(q=head;q->next!=NULL;q=q->next)
    {
        //往后找
        for(p=q->next;p->next!=NULL;p=p->next)
        {
            //atoi时将字符串转换为整型
            //当链表后面的宿舍号比前面的小时
            if(flag)
            {
                    if(atoi(p->next->num)<atoi(q->next->num))
            {
                //进行顺序调整
                if(q->next==p)
                {
                    temp=p->next;
                    p->next=p->next->next;
                    temp->next=p;
                    q->next=temp;
                    p=temp;
                }
                else
                {
                    temp=p->next;
                    p->next=q->next;
                    q->next=temp;
                    temp=p->next->next;
                    p->next->next=q->next->next;
                    q->next->next=temp;
                }
            }
            }
            else
            {
                if(atoi(p->next->num)>atoi(q->next->num))
            {
                //进行顺序调整
                if(q->next==p)
                {
                    temp=p->next;
                    p->next=p->next->next;
                    temp->next=p;
                    q->next=temp;
                    p=temp;
                }
                else
                {
                    temp=p->next;
                    p->next=q->next;
                    q->next=temp;
                    temp=p->next->next;
                    p->next->next=q->next->next;
                    q->next->next=temp;
                }
            }

            }
        }
    }
    return head;
}

/*-------------------------------------------*/

//窗口类函数
//登陆view
void Login_View()
{
    GtkWidget *table;
    GtkWidget *label;
    GtkWidget *button;
    //验证码所需变量
    gchar *captcha1;
    captcha1=(gchar*)malloc(sizeof(gchar)*15);
    login.captcha=(gchar*)malloc(sizeof(gchar)*5);
    strcpy(captcha1,"验证码：");
    memset(login.captcha,0,sizeof(gchar)*5);
    //创建登陆窗口
    login.window=Create_Window(GTK_WINDOW_TOPLEVEL,"宿舍管理系统登陆",330,200,FALSE);
    //组合表建立
    table = gtk_table_new(7,4,TRUE);
    gtk_widget_show(table);
    gtk_container_add(GTK_CONTAINER(login.window),table);
    //用户名
    label = gtk_label_new("     用户名  :      ");
    gtk_table_attach(GTK_TABLE(table),label,0,1,1,2,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    login.user=Create_Entry(30,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),login.user,1,2,1,2,GTK_FILL,GTK_FILL,0,0);
    //密码
     label = gtk_label_new("     密码      :      ");
    gtk_table_attach(GTK_TABLE(table),label,0,1,2,3,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    login.password=Create_Entry(30,TRUE,FALSE);
    gtk_table_attach(GTK_TABLE(table),login.password,1,2,2,3,GTK_FILL,GTK_FILL,0,0);
    //验证码
    login.captcha=Captcha_Create();
    strcat(captcha1,login.captcha);
    label = gtk_label_new(captcha1);
    gtk_table_attach(GTK_TABLE(table),label,0,1,3,4,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    login.identify_code=Create_Entry(4,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),login.identify_code,1,2,3,4,GTK_FILL,GTK_FILL,0,0);
    //登陆
    button = gtk_button_new_with_label("登陆");
    gtk_table_attach(GTK_TABLE(table),button,0,1,5,6,GTK_FILL,GTK_FILL,5,0);
    g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(Login_Check),NULL);
    gtk_widget_show(button);
    //退出
    button = gtk_button_new_with_label("退出");
    gtk_table_attach(GTK_TABLE(table),button,1,2,5,6,GTK_FILL,GTK_FILL,0,0);
    g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(Quit_View),(gpointer)login.window);
    gtk_widget_show(button);

    //信号链接部分
     g_signal_connect_swapped(G_OBJECT(login.window), "delete_event",G_CALLBACK(Quit_View), (gpointer)login.window);
    //显示登陆界面
    gtk_widget_show(login.window);

}

//密码错误对话框
void Login_Password_Wrong()
{
    login.dialog=gtk_message_dialog_new((GtkWindow*)login.window,GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"密码错误！");
    //设置对话框标题
    gtk_window_set_title(GTK_WINDOW(login.dialog),"登录提示");
    //显示对话框
    //result来接受对话框的返回信息
    login.result=gtk_dialog_run(GTK_DIALOG(login.dialog));
    //根据对话框返回值进行操作
    switch(login.result)
    {
    //当按下的是OK键时
    case    GTK_RESPONSE_OK:
        gtk_widget_destroy(login.dialog);
        return;
    //当按下红叉时
    case    GTK_RESPONSE_DELETE_EVENT:
        gtk_widget_destroy(login.dialog);
        return;
    }
    return;
}

//密码错误超过3次对话框
void Login_Error()
{
    login.dialog=gtk_message_dialog_new((GtkWindow*)login.window,GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"密码错误超过三次！正在退出程序。");
    //设置对话框标题
    gtk_window_set_title(GTK_WINDOW(login.dialog),"登录提示");
    //显示对话框
    //result来接受对话框的返回信息
    login.result=gtk_dialog_run(GTK_DIALOG(login.dialog));
    //根据对话框返回值进行操作
    switch(login.result)
    {
    //当按下的是OK键时
    case    GTK_RESPONSE_OK:
        gtk_main_quit();
        return;
    //当按下红叉时
    case    GTK_RESPONSE_DELETE_EVENT:
        gtk_main_quit();
        return;
    }
    return;
}

//验证码错误窗口
void Login_Captcha_Wrong()
{
    login.dialog=gtk_message_dialog_new((GtkWindow*)login.window,GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"验证码错误！");
    //设置对话框标题
    gtk_window_set_title(GTK_WINDOW(login.dialog),"登录提示");
    //显示对话框
    //result来接受对话框的返回信息
    login.result=gtk_dialog_run(GTK_DIALOG(login.dialog));
    //根据对话框返回值进行操作
    switch(login.result)
    {
    //当按下的是OK键时
    case    GTK_RESPONSE_OK:
        gtk_widget_destroy(login.dialog);
        return;
    //当按下红叉时
    case    GTK_RESPONSE_DELETE_EVENT:
        gtk_widget_destroy(login.dialog);
        return;
    }
    return;
}

//用户不存在对话框
void Login_Username_Wrong()
{
    login.dialog=gtk_message_dialog_new((GtkWindow*)login.window,GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"用户名不存在！");
    //设置对话框标题
    gtk_window_set_title(GTK_WINDOW(login.dialog),"登录提示");
    //显示对话框
    //result来接受对话框的返回信息
    login.result=gtk_dialog_run(GTK_DIALOG(login.dialog));
    //根据对话框返回值进行操作
    switch(login.result)
    {
    //当按下的是OK键时
    case    GTK_RESPONSE_OK:
        gtk_widget_destroy(login.dialog);
        return;
    //当按下红叉时
    case    GTK_RESPONSE_DELETE_EVENT:
        gtk_widget_destroy(login.dialog);
        return;
    }
    return;
}

//程序退出对话框
gboolean Quit_View(GtkWidget *widget,gpointer window)
{
    //创建是否退出的对话框
    quit.dialog=gtk_message_dialog_new((GtkWindow*)login.window,GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"您确定要退出吗？");
    //设置对话框标题
    gtk_window_set_title(GTK_WINDOW(quit.dialog),"退出");
    //显示对话框
    //result来接受对话框的返回信息
    quit.result=gtk_dialog_run(GTK_DIALOG(quit.dialog));
    //根据对话框返回值进行操作
    switch(quit.result)
    {
    //当按下的是YES键时
    case    GTK_RESPONSE_YES:
        gtk_main_quit();
        //成功destroy返回FALSE
        return FALSE;
    //当按下的是NO键时
    case    GTK_RESPONSE_NO:
        gtk_widget_destroy(quit.dialog);
        return TRUE;
    //当按下红叉时
    case    GTK_RESPONSE_DELETE_EVENT:
        gtk_widget_destroy(quit.dialog);
        return TRUE;
    }
    return TRUE;
}

//菜单
void Menu_View()
{
    GtkWidget *table,*button;
    //创建菜单窗口
    menu.window=Create_Window(GTK_WINDOW_TOPLEVEL,"宿舍信息管理系统",450,300,FALSE);
    //组合表建立
    table = gtk_table_new(150,300,TRUE);
    gtk_widget_show(table);
    gtk_container_add(GTK_CONTAINER(menu.window),table);
     //整体概览
    button = gtk_button_new_with_label("楼舍信息概览");
    gtk_table_attach(GTK_TABLE(table),button,0,150,0,60,GTK_FILL,GTK_FILL,0,0);
    g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(Menu_To_Overview),NULL);
    gtk_widget_show(button);
    //信息添加
    button = gtk_button_new_with_label("信息添加");
    gtk_table_attach(GTK_TABLE(table),button,0,150,60,120,GTK_FILL,GTK_FILL,0,0);
    g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(Menu_To_Addimf),NULL);
    gtk_widget_show(button);
    //信息查询
    button=gtk_button_new_with_label("信息查询");
    gtk_table_attach(GTK_TABLE(table),button,0,150,120,180,GTK_FILL,GTK_FILL,0,0);
    g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(Menu_To_Search),NULL);
    gtk_widget_show(button);
    //信息修改
    button=gtk_button_new_with_label("信息修改");
    gtk_table_attach(GTK_TABLE(table),button,0,150,180,240,GTK_FILL,GTK_FILL,0,0);
    g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(Menu_To_Revise),NULL);
    gtk_widget_show(button);
    //退出
    button=gtk_button_new_with_label("退出");
    gtk_table_attach(GTK_TABLE(table),button,0,150,240,300,GTK_FILL,GTK_FILL,0,0);
    g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(Quit_View),NULL);
    gtk_widget_show(button);
    //信号链接部分
    g_signal_connect_swapped(G_OBJECT(menu.window), "delete_event",G_CALLBACK(Quit_View), (gpointer)menu.window);
    //显示
    gtk_widget_show(menu.window);
}

//宿舍概览
void Overview_View()
{
    gchar *da[8];//={"\0","\0","\0","\0","\0","\0","\0","\0"};
    int i;
    char name[30]="\0";
    DDATA *head ,*p ;
    overview.flag=1;
    //head=(DDATA*)malloc(sizeof(DDATA));
    overview.window = Create_Window(GTK_WINDOW_TOPLEVEL,"学生概览",500,600,FALSE);
    overview.clist = gtk_clist_new(8);
    //项目
    gtk_clist_set_column_title(GTK_CLIST(overview.clist),0,"宿舍号");
    gtk_clist_set_column_title(GTK_CLIST(overview.clist),1,"舍        长");
    gtk_clist_set_column_title(GTK_CLIST(overview.clist),2,"成        员");
    gtk_clist_set_column_title(GTK_CLIST(overview.clist),3,"成        员");
    gtk_clist_set_column_title(GTK_CLIST(overview.clist),4,"成        员");
    gtk_clist_set_column_title(GTK_CLIST(overview.clist),5,"成        员");
    gtk_clist_set_column_title(GTK_CLIST(overview.clist),6,"成        员");
    gtk_clist_set_column_title(GTK_CLIST(overview.clist),7,"成        员");
    //添加成员
    g_print("2222文件名字%s\n",menu.filename);
    strcpy(name,menu.filename);
    head = Read_Ddata(name);
    if(!head)
     g_print("fuck\n");
//    从链表中将信息添加到各自栏下
    g_print("1%s\n",head->next->num);
    for ( i=0;i<8;i++)
    da[i] = (gchar *)malloc(sizeof(gchar)*30);
    for(p=head->next;p!=NULL;p=p->next)
    {
//        g_print("2%s%s%s%s%s%s%s%s\n",p->num,p->captain,p->member[0],p->member[1],p->member[2],p->member[3],p->member[4]);
        strcpy(da[0],p->num);
        strcpy(da[1],p->captain);
        strcpy(da[2],p->member[0]);
        strcpy(da[3],p->member[1]);
        strcpy(da[4],p->member[2]);
        strcpy(da[5],p->member[3]);
        strcpy(da[6],p->member[4]);
        strcpy(da[7],p->member[5]);
        g_print("3%s %s %s %s %s %s %s %s\n",da[0],da[1],da[2],da[3],da[4],da[5],da[6],da[7]);
    gtk_clist_prepend(GTK_CLIST(overview.clist),da);
    }
    //添加完成显示
    gtk_clist_column_titles_show(GTK_CLIST(overview.clist));
    //捕捉select_row信号
    gtk_signal_connect(GTK_OBJECT(overview.clist),"click_column",GTK_SIGNAL_FUNC(select_row_callback),NULL);
    //将分栏列表添加到窗口
    gtk_container_add(GTK_CONTAINER(overview.window),overview.clist);
    //显示
    gtk_widget_show(overview.clist);
    gtk_widget_show(overview.window);
}

//从菜单页面到概览页面的选择楼号对话窗
gchar* Menu_To_Overview(GtkWidget*widget,gpointer gdata)
{
    GtkWidget *button;
    GtkWidget *table;
    GtkWidget *label;
    //声明组
    GSList *group=NULL;
    //隐藏菜单窗口
    gtk_widget_hide(menu.window);
    //创建对话窗
    menu.To_Overview_Window=Create_Window(GTK_WINDOW_TOPLEVEL,"选择楼号",240,240,FALSE);
    //创建组合表
    table=gtk_table_new(20,100,TRUE);
    //默认选择为一号楼
    strcpy(menu.filename,"Overview_1");
    //显示提示信息
    label = gtk_label_new("请选择您要概览的楼号");
    gtk_table_attach(GTK_TABLE(table),label,2,18,0,10,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);

    //创建选择按钮
    button=gtk_radio_button_new_with_label(group,"      一号楼");
    //把选择按钮加到组中
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    //把选择按钮加到组合表中
    gtk_table_attach(GTK_TABLE(table),button,5,15,10,20,GTK_FILL,GTK_FILL,0,0);
    //显示选择按钮
    gtk_widget_show(button);
    //信号链接
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Menu_To_Overview_Button_Check),(gpointer)&return_num[1]);
    //创建选择按钮
    button=gtk_radio_button_new_with_label(group,"      二号楼");
    //把选择按钮加到组中
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    //把选择按钮加到组合表中
    gtk_table_attach(GTK_TABLE(table),button,5,15,20,30,GTK_FILL,GTK_FILL,0,0);
    //显示选择按钮
    gtk_widget_show(button);
    //信号链接
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Menu_To_Overview_Button_Check),(gpointer)&return_num[2]);
    //创建选择按钮
    button=gtk_radio_button_new_with_label(group,"      三号楼");
    //把选择按钮加到组中
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    //把选择按钮加到组合表中
    gtk_table_attach(GTK_TABLE(table),button,5,15,30,40,GTK_FILL,GTK_FILL,0,0);
    //显示选择按钮
    gtk_widget_show(button);
    //信号链接
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Menu_To_Overview_Button_Check),(gpointer)&return_num[3]);
    //创建选择按钮
    button=gtk_radio_button_new_with_label(group,"      四号楼");
    //把选择按钮加到组中
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    //把选择按钮加到组合表中
    gtk_table_attach(GTK_TABLE(table),button,5,15,40,50,GTK_FILL,GTK_FILL,0,0);
    //显示选择按钮
    gtk_widget_show(button);
    //信号链接
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Menu_To_Overview_Button_Check),(gpointer)&return_num[4]);

    //确定按钮
    button=gtk_button_new_with_label("确定");
    gtk_table_attach(GTK_TABLE(table),button,0,20,50,60,GTK_FILL,GTK_FILL,0,0);
    g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(Overview_View),NULL);
    gtk_widget_show(button);

    //信号链接
    g_signal_connect(G_OBJECT(menu.To_Overview_Window),"delete_event",G_CALLBACK(Menu_To_Overview_Return_Menu),NULL);

    //把组合表放入窗口
    gtk_container_add(GTK_CONTAINER(menu.To_Overview_Window),table);

    //显示
    gtk_widget_show(table);
    gtk_widget_show(menu.To_Overview_Window);
    return NULL;

}

//添加信息窗口
void Addimf_View()
{
    GtkWidget *button;
    GtkWidget *table;
    GtkWidget *label;
    //声明组
    GSList *group=NULL;
    //隐藏菜单窗口
    gtk_widget_hide(menu.window);
    //创建对话窗
    add.choose_window=Create_Window(GTK_WINDOW_TOPLEVEL,"选择楼号",240,240,FALSE);
    //创建组合表
    table=gtk_table_new(20,100,TRUE);
    //显示提示信息
    label = gtk_label_new("请选择新增宿舍的楼号");
    gtk_table_attach(GTK_TABLE(table),label,2,18,0,10,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //默认选择为一号楼
    add.number=1;
    //创建选择按钮
    button=gtk_radio_button_new_with_label(group,"      一号楼");
    //把选择按钮加到组中
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    //把选择按钮加到组合表中
    gtk_table_attach(GTK_TABLE(table),button,5,15,10,20,GTK_FILL,GTK_FILL,0,0);
    //显示选择按钮
    gtk_widget_show(button);
    //信号链接
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Menu_To_Addimf_Button_Check),(gpointer)&return_num[1]);
    //创建选择按钮
    button=gtk_radio_button_new_with_label(group,"      二号楼");
    //把选择按钮加到组中
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    //把选择按钮加到组合表中
    gtk_table_attach(GTK_TABLE(table),button,5,15,20,30,GTK_FILL,GTK_FILL,0,0);
    //显示选择按钮
    gtk_widget_show(button);
    //信号链接
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Menu_To_Addimf_Button_Check),(gpointer)&return_num[2]);
    //创建选择按钮
    button=gtk_radio_button_new_with_label(group,"      三号楼");
    //把选择按钮加到组中
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    //把选择按钮加到组合表中
    gtk_table_attach(GTK_TABLE(table),button,5,15,30,40,GTK_FILL,GTK_FILL,0,0);
    //显示选择按钮
    gtk_widget_show(button);
    //信号链接
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Menu_To_Addimf_Button_Check),(gpointer)&return_num[3]);
    //创建选择按钮
    button=gtk_radio_button_new_with_label(group,"      四号楼");
    //把选择按钮加到组中
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    //把选择按钮加到组合表中
    gtk_table_attach(GTK_TABLE(table),button,5,15,40,50,GTK_FILL,GTK_FILL,0,0);
    //显示选择按钮
    gtk_widget_show(button);
    //信号链接
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Menu_To_Addimf_Button_Check),(gpointer)&return_num[4]);

    //确定按钮
    button=gtk_button_new_with_label("确定");
    gtk_table_attach(GTK_TABLE(table),button,0,20,50,60,GTK_FILL,GTK_FILL,0,0);
    g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(Addimf_Choose_To_Overview),NULL);
    gtk_widget_show(button);

    //信号链接
    g_signal_connect(G_OBJECT(add.choose_window),"delete_event",G_CALLBACK(Addimf_Choose_Return),NULL);

    //把组合表放入窗口
    gtk_container_add(GTK_CONTAINER(add.choose_window),table);

    //显示
    gtk_widget_show(table);
    gtk_widget_show(add.choose_window);
    return;
}

//添加大致信息页面
void Addimf_Over_View()
{
    GtkWidget *button;
    GtkWidget *label;
    GtkWidget *table;
    //创建信息填写窗口
    add.over_window=Create_Window(GTK_WINDOW_TOPLEVEL,"填写宿舍信息",280,200,FALSE);
    //组合表建立
    table = gtk_table_new(5,6,TRUE);
    gtk_widget_show(table);
    gtk_container_add(GTK_CONTAINER(add.over_window),table);
    //宿舍号
    label = gtk_label_new("宿舍号：");
    gtk_table_attach(GTK_TABLE(table),label,0,2,1,2,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    Addoverimf.num=Create_Entry(3,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),Addoverimf.num,2,5,1,2,GTK_FILL,GTK_FILL,0,0);
    //舍长姓名
     label = gtk_label_new("舍长姓名：");
    gtk_table_attach(GTK_TABLE(table),label,0,2,2,3,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    Addoverimf.captain=Create_Entry(30,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),Addoverimf.captain,2,5,2,3,GTK_FILL,GTK_FILL,0,0);
    //宿舍人数
    label = gtk_label_new("宿舍人数：");
    gtk_table_attach(GTK_TABLE(table),label,0,2,3,4,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    Addoverimf.num_people=Create_Entry(1,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),Addoverimf.num_people,2,5,3,4,GTK_FILL,GTK_FILL,0,0);
    //下一步
    button = gtk_button_new_with_label("下一步");
    gtk_table_attach(GTK_TABLE(table),button,0,5,5,6,GTK_FILL,GTK_FILL,5,0);
    g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(Addimf_Overview_Save),NULL);
    gtk_widget_show(button);
    //信号链接部分
    g_signal_connect_swapped(G_OBJECT(add.over_window), "delete_event",G_CALLBACK(Addimf_Overview_Quit_View), NULL);
    //显示登陆界面
    gtk_widget_show(add.over_window);
}

//添加大致信息时人数不对警告窗口
void Addimf_Overview_Num_Wrong_View()
{
    gint result;
    Addoverimf.num_wrong_dialog=gtk_message_dialog_new((GtkWindow*)add.over_window,GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"您所输入的人数不在可接受范围内！");
    //设置对话框标题
    gtk_window_set_title(GTK_WINDOW(Addoverimf.num_wrong_dialog),"错误提示提示");
    //显示对话框
    //result来接受对话框的返回信息
    result=gtk_dialog_run(GTK_DIALOG(Addoverimf.num_wrong_dialog));
    //根据对话框返回值进行操作
    switch(result)
    {
    //当按下的是OK键时
    case    GTK_RESPONSE_OK:
        gtk_widget_destroy(Addoverimf.num_wrong_dialog);
        return;
    //当按下红叉时
    case    GTK_RESPONSE_DELETE_EVENT:
        gtk_widget_destroy(Addoverimf.num_wrong_dialog);
        return;
    }
    return;
}

//添加大致信息时退出对话框
gboolean Addimf_Overview_Quit_View()
{
    //创建是否退出的对话框
    add.over_quit_window=gtk_message_dialog_new((GtkWindow*)add.over_window,GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"添加尚未成功，您确定要返回吗？");
    //设置对话框标题
    gtk_window_set_title(GTK_WINDOW(add.over_quit_window),"取消添加");
    //显示对话框
    //result来接受对话框的返回信息
    add.result=gtk_dialog_run(GTK_DIALOG(add.over_quit_window));
    //根据对话框返回值进行操作
    switch(add.result)
    {
    //当按下的是YES键时
    case    GTK_RESPONSE_YES:
        gtk_widget_destroy(add.over_quit_window);
        Addimf_Overview_return();
        return FALSE;
    //当按下的是NO键时
    case    GTK_RESPONSE_NO:
        gtk_widget_destroy(add.over_quit_window);
        return TRUE;
    //当按下红叉时
    case    GTK_RESPONSE_DELETE_EVENT:
        gtk_widget_destroy(add.over_quit_window);
        return TRUE;
    }
    return TRUE;
}

//学生详细信息添加
void Addimf_Stu_View()
{
    char a[30]="正在添加第";
    char b[]="个学生";
    GtkWidget *button;
    GtkWidget *label;
    GtkWidget *table;
    GSList *group=NULL;
    add.member_window=Create_Window(GTK_WINDOW_TOPLEVEL,"学生详细信息",350,370,TRUE);
    table = gtk_table_new(20,100,TRUE);
    gtk_container_add(GTK_CONTAINER(add.member_window),table);
    //显示正在添加
    strcat(a,(char*)&stu_info.addimf_stu_num);
    strcat(a,b);
    label = gtk_label_new(a);
    gtk_table_attach(GTK_TABLE(table),label,5,15,2,10,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //姓名
    label = gtk_label_new("     姓名               :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,10,20,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    stu_info.name=Create_Entry(30,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),stu_info.name,10,20,10,20,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(stu_info.name);
    //性别
    //男
    d_imf.member[stu_info.addimf_stu_num-49].sex=TRUE;
    label = gtk_label_new("     性别               :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,20,30,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    button=gtk_radio_button_new_with_label(group," 男");
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    //信号链接
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Stu_Sex_Button_Check),(gpointer)&return_num[1]);
    gtk_table_attach(GTK_TABLE(table),button,10,15,20,30,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(button);
    //女
    button = gtk_radio_button_new_with_label(group,"女");
    group = gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    gtk_table_attach(GTK_TABLE(table),button,15,20,20,30,GTK_FILL,GTK_FILL,0,0);
    //信号链接
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Stu_Sex_Button_Check),(gpointer)&return_num[0]);
    gtk_widget_show(button);
    //班级
    label = gtk_label_new("     班级               :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,30,40,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    stu_info.classes=Create_Entry(30,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),stu_info.classes,10,20,30,40,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(stu_info.classes);
    //电话
    label = gtk_label_new("     电话               :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,40,50,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    stu_info.tel=Create_Entry(30,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),stu_info.tel,10,20,40,50,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(stu_info.tel);
    //家长姓名
    label = gtk_label_new("     家长姓名        :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,50,60,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    stu_info.parent_name=Create_Entry(30,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),stu_info.parent_name,10,20,50,60,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(stu_info.parent_name);
    //家长电话
    label = gtk_label_new("     家长电话       :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,60,70,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    stu_info.parent_tel=Create_Entry(30,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),stu_info.parent_tel,10,20,60,70,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(stu_info.parent_tel);
    //上一步
    button = gtk_button_new_with_label("上一步");
    gtk_table_attach(GTK_TABLE(table),button,0,10,80,90,GTK_FILL,GTK_FILL,5,0);
    g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(Addimf_Stu_Goback),NULL);
    gtk_widget_show(button);
    //确定
    if(stu_info.addimf_stu_num<d_imf.num_people&&d_imf.num_people>=48)
    {
        button = gtk_button_new_with_label("下一步");
        gtk_table_attach(GTK_TABLE(table),button,10,20,80,90,GTK_FILL,GTK_FILL,0,0);
        g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(Addimf_Stu_Check),(gpointer)login.window);
        gtk_widget_show(button);
    }
    else if(stu_info.addimf_stu_num==d_imf.num_people)
    {
        button = gtk_button_new_with_label("确定");
        gtk_table_attach(GTK_TABLE(table),button,10,20,80,90,GTK_FILL,GTK_FILL,0,0);
        g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(Addimf_Stu_Save),(gpointer)login.window);
        gtk_widget_show(button);
    }
    //关闭信号链接
    g_signal_connect(G_OBJECT(add.member_window),"delete_event",G_CALLBACK(Addimf_Stu_Quit_View),(gpointer)add.member_window);
    //显示表格
    gtk_widget_show_all(table);
    //显示窗口
    gtk_widget_show_all(add.member_window);
}

//添加信息存储成功弹窗
void Addimf_Save_Success()
{
    gint result;
    add.Success=gtk_message_dialog_new((GtkWindow*)add.member_window,GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"存储成功！");
    //设置对话框标题
    gtk_window_set_title(GTK_WINDOW(add.Success),"存储提示");
    //显示对话框
    //result来接受对话框的返回信息
    result=gtk_dialog_run(GTK_DIALOG(add.Success));
    //根据对话框返回值进行操作
    switch(result)
    {
    //当按下的是OK键时
    case    GTK_RESPONSE_OK:
        gtk_widget_destroy(add.Success);
        return;
    //当按下红叉时
    case    GTK_RESPONSE_DELETE_EVENT:
        gtk_widget_destroy(add.Success);
        return;
    }
    return;
}

//添加信息存储失败弹窗
void Addimf_Save_Error()
{
    gint result;
    add.Error=gtk_message_dialog_new((GtkWindow*)add.member_window,GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"存储失败！");
    //设置对话框标题
    gtk_window_set_title(GTK_WINDOW(add.Error),"存储提示");
    //显示对话框
    //result来接受对话框的返回信息
    result=gtk_dialog_run(GTK_DIALOG(add.Error));
    //根据对话框返回值进行操作
    switch(result)
    {
    //当按下的是OK键时
    case    GTK_RESPONSE_OK:
        gtk_widget_destroy(add.Error);
        return;
    //当按下红叉时
    case    GTK_RESPONSE_DELETE_EVENT:
        gtk_widget_destroy(add.Error);
        return;
    }
    return;
}

//添加详细学生信息时退出对话框
gboolean Addimf_Stu_Quit_View()
{
    //创建是否退出的对话框
    add.stu_quit_window=gtk_message_dialog_new((GtkWindow*)add.member_window,GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"添加尚未成功，您确定要返回吗？");
    //设置对话框标题
    gtk_window_set_title(GTK_WINDOW(add.stu_quit_window),"取消添加");
    //显示对话框
    //result来接受对话框的返回信息
    add.result=gtk_dialog_run(GTK_DIALOG(add.stu_quit_window));
    //根据对话框返回值进行操作
    switch(add.result)
    {
    //当按下的是YES键时
    case    GTK_RESPONSE_YES:
        gtk_widget_destroy(add.stu_quit_window);
        Addimf_Stu_return();
        return FALSE;
    //当按下的是NO键时
    case    GTK_RESPONSE_NO:
        gtk_widget_destroy(add.stu_quit_window);
        return TRUE;
    //当按下红叉时
    case    GTK_RESPONSE_DELETE_EVENT:
        gtk_widget_destroy(add.stu_quit_window);
        return TRUE;
    }
    return TRUE;
}

//查询菜单
void Search_Choose_Menu_View()
{

    //声明变量
    GtkWidget *button;
    GtkWidget *label;
    GtkWidget *table;
    GSList *group =NULL;
    //初始化选择学生
    searchparameter.dorm_or_stu=FALSE;
    //窗口创建
    searchview.choose_menu_window = Create_Window(GTK_WINDOW_TOPLEVEL,"信息查询",190,215,FALSE);
    //表格创建
    table = gtk_table_new(20,50,TRUE);
    gtk_container_add(GTK_CONTAINER(searchview.choose_menu_window),table);
    //标签创建
    label = gtk_label_new("请选择查询方式");
    gtk_table_attach(GTK_TABLE(table),label,2,15,2,10,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //按钮创建
    button=gtk_radio_button_new_with_label(group," 学        生");
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    //信号链接
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Search_Choose_Menu_Button_Check),(gpointer)&return_num[0]);
    gtk_table_attach(GTK_TABLE(table),button,5,15,10,20,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(button);
    button = gtk_radio_button_new_with_label(group,"宿       舍");
    group = gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    gtk_table_attach(GTK_TABLE(table),button,5,15,20,30,GTK_FILL,GTK_FILL,0,0);
    //信号链接
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Search_Choose_Menu_Button_Check),(gpointer)&return_num[1]);
    gtk_widget_show(button);
    //确定按钮
    button =gtk_button_new_with_label("确        定");
    gtk_table_attach(GTK_TABLE(table),button,2,15,40,50,GTK_FILL,GTK_FILL,0,0);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Search_Menu_To_Search),(gpointer)&return_num[1]);
    gtk_widget_show(button);
    //信号链接
    g_signal_connect(G_OBJECT(searchview.choose_menu_window),"delete_event",G_CALLBACK(Search_Choose_Menu_Return),NULL);
    //显示表格
    gtk_widget_show(table);
    //显示窗口
    gtk_widget_show(searchview.choose_menu_window);
}

//查询宿舍选择
void Search_Choose_Dorm_View()
{
    //声明变量
    GtkWidget *button;
    GtkWidget *label;
    GtkWidget *table;
    GSList *group=NULL;
    searchparameter.num_dorm=1;
    //创建窗口
    searchview.choose_dorm_window = Create_Window(GTK_WINDOW_TOPLEVEL,"宿舍查询",400,380,FALSE);
    //创建表格
    table = gtk_table_new(30,100,TRUE);
    gtk_container_add(GTK_CONTAINER(searchview.choose_dorm_window),table);
    //创建标签
    label = gtk_label_new("请选择楼号            :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,10,20,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //创建选择按钮
    button=gtk_radio_button_new_with_label(group,"      一号楼");
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    gtk_table_attach(GTK_TABLE(table),button,10,20,10,20,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(button);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Dorm_Menu_To_Search_Button_Check),(gpointer)&return_num[1]);
    //创建选择按钮
    button=gtk_radio_button_new_with_label(group,"      二号楼");
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    gtk_table_attach(GTK_TABLE(table),button,10,20,20,30,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(button);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Dorm_Menu_To_Search_Button_Check),(gpointer)&return_num[2]);
    //创建选择按钮
    button=gtk_radio_button_new_with_label(group,"      三号楼");
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    gtk_table_attach(GTK_TABLE(table),button,10,20,30,40,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(button);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Dorm_Menu_To_Search_Button_Check),(gpointer)&return_num[3]);
    //创建选择按钮
    button=gtk_radio_button_new_with_label(group,"      四号楼");
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    gtk_table_attach(GTK_TABLE(table),button,10,20,40,50,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(button);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Dorm_Menu_To_Search_Button_Check),(gpointer)&return_num[4]);

    //创建宿舍号
    label = gtk_label_new("         宿舍号         :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,60,70,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    searchparameter.dorm_number= Create_Entry(3,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),searchparameter.dorm_number,10,20,60,70,GTK_FILL,GTK_FILL,0,0);
    //创建确认按钮
    button = gtk_button_new_with_label("确   认");
    gtk_table_attach(GTK_TABLE(table),button,5,15,80,90,GTK_FILL,GTK_FILL,0,0);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Dorm_Menu_To_Dorm),NULL);
    gtk_widget_show(button);
    //信号链接
    g_signal_connect(G_OBJECT(searchview.choose_dorm_window),"delete_event",G_CALLBACK(Search_Choose_Dorm_Return),NULL);
    //显示表格
    gtk_widget_show(table);
    //显示窗口
    gtk_widget_show(searchview.choose_dorm_window);
}

//学生信息查询窗口
void Search_Choose_Stu_View()
{
    //变量声明
    GtkWidget* label;
    GtkWidget* table;
    GtkWidget* button;
    //创建窗口
    searchview.choose_stu_window=Create_Window(GTK_WINDOW_TOPLEVEL,"学生查询",400,180,FALSE);
    //创建表格
    table = gtk_table_new(20,50,TRUE);
    gtk_container_add(GTK_CONTAINER(searchview.choose_stu_window),table);
    //创建标签
    label = gtk_label_new("请输入学生名 :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,10,20,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //创建输入
    searchparameter.stu_name= Create_Entry(30,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),searchparameter.stu_name,10,20,10,20,GTK_FILL,GTK_FILL,0,0);
    //创建按钮
    button = gtk_button_new_with_label("确定");
    gtk_table_attach(GTK_TABLE(table),button,5,15,30,40,GTK_FILL,GTK_FILL,0,0);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Stu_Menu_To_Stu),NULL);
    gtk_widget_show(button);
    //信号链接
    g_signal_connect(G_OBJECT(searchview.choose_stu_window),"delete_event",G_CALLBACK(Search_Choose_Stu_Return),NULL);
    //显示表格
    gtk_widget_show(table);
    //显示窗口
    gtk_widget_show(searchview.choose_stu_window);
}

//宿舍结果显示窗口
void Search_Dorm_View()
{
    char captain[50]="舍长        :",num[30]="宿舍号        :",*member[6];
    GtkWidget* label;
    GtkWidget*  table;
    int i;
    //初始化
    strcat(num,ddata.num);
    strcat(captain,ddata.captain);
    for(i=0;i<6;i++)
    {
        member[i]=(char *)malloc(sizeof(char)*50);
        strcpy(member[i],"成员        :");
        strcat(member[i],ddata.member[i]);
        g_print("%s\n",member[i]);
    }
    //窗口创建
    searchview.dorm_window = Create_Window(GTK_WINDOW_TOPLEVEL,"查询信息显示",250,140,FALSE);
    //表格创建
    table = gtk_table_new(21,100,TRUE);
    gtk_container_add(GTK_CONTAINER(searchview.dorm_window),table);
    //宿舍号显示
    label = gtk_label_new(num);
    gtk_table_attach(GTK_TABLE(table),label,5,15,0,10,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //舍长显示
    label = gtk_label_new(captain);
    gtk_table_attach(GTK_TABLE(table),label,0,10,20,30,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //成员1
    label = gtk_label_new(member[0]);
    gtk_table_attach(GTK_TABLE(table),label,0,10,30,40,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //成员2
    label = gtk_label_new(member[1]);
    gtk_table_attach(GTK_TABLE(table),label,10,20,30,40,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //成员3
    label = gtk_label_new(member[2]);
    gtk_table_attach(GTK_TABLE(table),label,0,10,40,50,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //成员4
    label = gtk_label_new(member[3]);
    gtk_table_attach(GTK_TABLE(table),label,10,20,40,50,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //成员5
    label = gtk_label_new(member[4]);
    gtk_table_attach(GTK_TABLE(table),label,0,10,50,60,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //成员6
    label = gtk_label_new(member[5]);
    gtk_table_attach(GTK_TABLE(table),label,10,20,50,60,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //信号链接
    g_signal_connect(G_OBJECT(searchview.dorm_window),"delete_event",G_CALLBACK(Search_Dorm_Return),NULL);
    //显示
    gtk_widget_show(table);
    gtk_widget_show(searchview.dorm_window);

}

//学生信息结果显示
void Search_Stu_View()
{
    gchar *sex[2]={"女","男"};
    gchar *da[6];
    int i,j=0;
    searchview.stu_window=Create_Window(GTK_WINDOW_TOPLEVEL,"学生信息",500,600,FALSE);
    searchview.clist = gtk_clist_new(6);
    //项目
    gtk_clist_set_column_title(GTK_CLIST(searchview.clist),0,"姓        名");
    gtk_clist_set_column_title(GTK_CLIST(searchview.clist),1,"性        别");
    gtk_clist_set_column_title(GTK_CLIST(searchview.clist),2,"班        级");
    gtk_clist_set_column_title(GTK_CLIST(searchview.clist),3,"电        话");
    gtk_clist_set_column_title(GTK_CLIST(searchview.clist),4,"家长姓名");
    gtk_clist_set_column_title(GTK_CLIST(searchview.clist),5,"家长电话");
    for ( i=0;i<6;i++)
    da[i] = (gchar *)malloc(sizeof(gchar)*30);
    do
    {
        strcpy(da[0],stu_search[j]->name);
        //str*cpy(da[1],stu_search[j]->sex);
        if(stu_search[j]->sex)
            strcpy(da[1],sex[1]);
        else
            strcpy(da[1],sex[1]);
        strcpy(da[2],stu_search[j]->classes);
        strcpy(da[3],stu_search[j]->tel);
        strcpy(da[4],stu_search[j]->parent_name);
        strcpy(da[5],stu_search[j]->parent_tel);
        j++;
        //g_print("3%s %s %s %s %s %s %s %s\n",da[0],da[1],da[2],da[3],da[4],da[5],da[6],da[7]);
    gtk_clist_prepend(GTK_CLIST(searchview.clist),da);
    }while(stu_search[j]!=NULL);
    //添加完成显示
    gtk_clist_column_titles_show(GTK_CLIST(searchview.clist));
    //添加
    gtk_container_add(GTK_CONTAINER(searchview.stu_window),searchview.clist);
    //信号链接
    g_signal_connect(G_OBJECT(searchview.stu_window),"delete_event",G_CALLBACK(Search_Stu_Return),NULL);
    //显示
    gtk_widget_show(searchview.clist);
    gtk_widget_show(searchview.stu_window);


}

//修改选择窗口
void Revise_Choose_View()
{
    //声明变量
    GtkWidget *button;
    GtkWidget *label;
    GtkWidget *table;
    GSList *group =NULL;
    //初始化选择学生
    revise_imf.dorm_or_stu=FALSE;
    //窗口创建
    revise.choose_menu_window = Create_Window(GTK_WINDOW_TOPLEVEL,"选择类型",190,215,FALSE);
    //表格创建
    table = gtk_table_new(20,50,TRUE);
    gtk_container_add(GTK_CONTAINER(revise.choose_menu_window),table);
    //标签创建
    label = gtk_label_new("请选择修改类型");
    gtk_table_attach(GTK_TABLE(table),label,2,15,2,10,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //按钮创建
    button=gtk_radio_button_new_with_label(group," 学        生");
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    //信号链接
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Revise_Choose_Menu_Button_Check),(gpointer)&return_num[0]);
    gtk_table_attach(GTK_TABLE(table),button,5,15,10,20,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(button);
    button = gtk_radio_button_new_with_label(group,"宿       舍");
    group = gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    gtk_table_attach(GTK_TABLE(table),button,5,15,20,30,GTK_FILL,GTK_FILL,0,0);
    //信号链接
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Revise_Choose_Menu_Button_Check),(gpointer)&return_num[1]);
    gtk_widget_show(button);
    //确定按钮
    button =gtk_button_new_with_label("确        定");
    gtk_table_attach(GTK_TABLE(table),button,2,15,40,50,GTK_FILL,GTK_FILL,0,0);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Revise_Menu_To_Get),(gpointer)&return_num[1]);
    gtk_widget_show(button);
    //delete_event信号链接
    g_signal_connect(G_OBJECT(revise.choose_menu_window),"delete_event",G_CALLBACK(Revise_Choose_Return),NULL);
    //显示表格
    gtk_widget_show(table);
    //显示窗口
    gtk_widget_show(revise.choose_menu_window);
}

//修改宿舍信息获取窗口
void Revise_Dorm_Get_View()
{
    //声明变量
    GtkWidget *button;
    GtkWidget *label;
    GtkWidget *table;
    GSList *group=NULL;
    //初始化楼号
    revise_imf.num_dorm=1;
    //创建窗口
    revise.dorm_get_window = Create_Window(GTK_WINDOW_TOPLEVEL,"宿舍修改",400,380,FALSE);
    //创建表格
    table = gtk_table_new(30,100,TRUE);
    gtk_container_add(GTK_CONTAINER(revise.dorm_get_window),table);
    //创建标签
    label = gtk_label_new("请选择楼号            :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,10,20,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //创建选择按钮
    button=gtk_radio_button_new_with_label(group,"      一号楼");
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    gtk_table_attach(GTK_TABLE(table),button,10,20,10,20,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(button);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Revise_Dorm_Get_Button_Check),(gpointer)&return_num[1]);
    //创建选择按钮
    button=gtk_radio_button_new_with_label(group,"      二号楼");
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    gtk_table_attach(GTK_TABLE(table),button,10,20,20,30,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(button);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Revise_Dorm_Get_Button_Check),(gpointer)&return_num[2]);
    //创建选择按钮
    button=gtk_radio_button_new_with_label(group,"      三号楼");
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    gtk_table_attach(GTK_TABLE(table),button,10,20,30,40,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(button);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Revise_Dorm_Get_Button_Check),(gpointer)&return_num[3]);
    //创建选择按钮
    button=gtk_radio_button_new_with_label(group,"      四号楼");
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    gtk_table_attach(GTK_TABLE(table),button,10,20,40,50,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(button);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Revise_Dorm_Get_Button_Check),(gpointer)&return_num[4]);

    //创建宿舍号
    label = gtk_label_new("         宿舍号         :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,60,70,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    revise.dorm_num = Create_Entry(3,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),revise.dorm_num,10,20,60,70,GTK_FILL,GTK_FILL,0,0);
    //创建确认按钮
    button = gtk_button_new_with_label("确   认");
    gtk_table_attach(GTK_TABLE(table),button,5,15,80,90,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(button);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Revise_Dorm_Check),NULL);

    //delete_event信号链接
    g_signal_connect(G_OBJECT(revise.dorm_get_window),"delete_event",G_CALLBACK(Revise_Dorm_Get_Return),NULL);
    //显示表格
    gtk_widget_show(table);
    //显示窗口
    gtk_widget_show(revise.dorm_get_window);

}

//修改学生信息录入窗口
void Revise_Stu_Get_View()
{
    //变量声明
    GtkWidget* label;
    GtkWidget* table;
    GtkWidget* button;
    //创建窗口
    revise.stu_get_window=Create_Window(GTK_WINDOW_TOPLEVEL,"修改学生",400,180,FALSE);
    //创建表格
    table = gtk_table_new(20,50,TRUE);
    gtk_container_add(GTK_CONTAINER(revise.stu_get_window),table);
    //创建标签
    label = gtk_label_new("请输入学生名 :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,10,20,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //创建输入
    revise.stu_name = Create_Entry(30,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),revise.stu_name,10,20,10,20,GTK_FILL,GTK_FILL,0,0);
    //创建按钮
    button = gtk_button_new_with_label("确定");
    gtk_table_attach(GTK_TABLE(table),button,5,15,30,40,GTK_FILL,GTK_FILL,0,0);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Revise_Stu_To_Get),NULL);
    gtk_widget_show(button);
    //delete_event信号链接
    g_signal_connect(G_OBJECT(revise.stu_get_window),"delete_event",G_CALLBACK(Revise_Stu_Get_Return),NULL);
    //显示表格
    gtk_widget_show(table);
    //显示窗口
    gtk_widget_show(revise.stu_get_window);
}

//修改学生信息确认窗口
void Revise_Stu_Isok(GtkWidget* widget,gpointer data)
{
    //char a[30]="正在添加第";
    //char b[]="个学生";
    GtkWidget *button;
    GtkWidget *label;
    GtkWidget *table;
    int k=*(int*) data;
    GSList *group=NULL;
    add.member_window=Create_Window(GTK_WINDOW_TOPLEVEL,"学生详细信息确认",350,370,TRUE);
    table = gtk_table_new(20,100,TRUE);
    gtk_container_add(GTK_CONTAINER(add.member_window),table);
    //显示正在添加
    //strcat(a,(char*)&stu_info.addimf_stu_num);
    //strcat(a,b);
     g_print("OK5\n");
    label = gtk_label_new("学生详细信息确认");
    gtk_table_attach(GTK_TABLE(table),label,5,15,2,10,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //姓名
    label = gtk_label_new("     姓名               :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,10,20,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    stu_info.name=Create_Entry(30,TRUE,TRUE);
    gtk_entry_set_text(GTK_ENTRY(stu_info.name),stu_search[k]->name);
    gtk_table_attach(GTK_TABLE(table),stu_info.name,10,20,10,20,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(stu_info.name);
    //性别
    //男
     g_print("OK6\n");
    //d_imf.member[stu_info.addimf_stu_num-49].sex=TRUE;
    label = gtk_label_new("     性别               :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,20,30,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    button=gtk_radio_button_new_with_label(group," 男");
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    //信号链接
    //g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Stu_Sex_Button_Check),(gpointer)&return_num[1]);
    gtk_table_attach(GTK_TABLE(table),button,10,15,20,30,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(button);
    //女
    button = gtk_radio_button_new_with_label(group,"女");
    group = gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    gtk_table_attach(GTK_TABLE(table),button,15,20,20,30,GTK_FILL,GTK_FILL,0,0);
    //信号链接
    //g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Stu_Sex_Button_Check),(gpointer)&return_num[0]);
    gtk_widget_show(button);
    //班级
     g_print("OK8\n");
    label = gtk_label_new("     班级               :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,30,40,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    stu_info.classes=Create_Entry(30,TRUE,TRUE);
    gtk_entry_set_text(GTK_ENTRY(stu_info.classes),stu_search[k]->classes);
    gtk_table_attach(GTK_TABLE(table),stu_info.classes,10,20,30,40,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(stu_info.classes);
    //电话
    label = gtk_label_new("     电话               :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,40,50,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    stu_info.tel=Create_Entry(30,TRUE,TRUE);
    gtk_entry_set_text(GTK_ENTRY(stu_info.tel),stu_search[k]->tel);
    gtk_table_attach(GTK_TABLE(table),stu_info.tel,10,20,40,50,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(stu_info.tel);
    //家长姓名
     g_print("OK9\n");
    label = gtk_label_new("     家长姓名        :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,50,60,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    stu_info.parent_name=Create_Entry(30,TRUE,TRUE);
    gtk_entry_set_text(GTK_ENTRY(stu_info.parent_name),stu_search[k]->parent_name);
    gtk_table_attach(GTK_TABLE(table),stu_info.parent_name,10,20,50,60,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(stu_info.parent_name);
    //家长电话
    label = gtk_label_new("     家长电话       :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,60,70,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    stu_info.parent_tel=Create_Entry(30,TRUE,TRUE);
    gtk_entry_set_text(GTK_ENTRY(stu_info.parent_tel),stu_search[k]->parent_tel);
    gtk_table_attach(GTK_TABLE(table),stu_info.parent_tel,10,20,60,70,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(stu_info.parent_tel);
    //上一步
     g_print("OK7\n");
    button = gtk_button_new_with_label("确认");
    gtk_table_attach(GTK_TABLE(table),button,0,10,80,90,GTK_FILL,GTK_FILL,5,0);
    //g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(Addimf_Stu_Goback),NULL);
    gtk_widget_show(button);
    button = gtk_button_new_with_label("取消");
    gtk_table_attach(GTK_TABLE(table),button,10,20,80,90,GTK_FILL,GTK_FILL,0,0);
    g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(gtk_widget_destroy),add.member_window);
    gtk_widget_show(button);
    //关闭信号链接
    //g_signal_connect(G_OBJECT(add.member_window),"delete_event",G_CALLBACK(Addimf_Stu_Quit_View),(gpointer)add.member_window);
    //显示表格
    gtk_widget_show_all(table);
    //显示窗口
    gtk_widget_show_all(add.member_window);
}

//修改_宿舍确认窗口
void Revise_Dorm_Check_View(LINKLIST*p)
{
    char captain[50]={"舍长        :"},num[30]={"宿舍号        :"},*member[6];
    GtkWidget* label;
    GtkWidget* table;
    GtkWidget* button;
    int i;
    //初始化
    strcat(num,p->dormitory.num);
    strcat(captain,p->dormitory.captain);
    for(i=0;i<6;i++)
    {
        member[i]=(char *)malloc(sizeof(char)*50);
        strcpy(member[i],"成员        :");
        strcat(member[i],p->dormitory.member[i].name);
        g_print("%s\n",member[i]);
    }
    //窗口创建
    revise.dorm_check_dialog = Create_Window(GTK_WINDOW_TOPLEVEL,"信息确认",240,280,FALSE);
    //表格创建
    table = gtk_table_new(21,100,TRUE);
    gtk_container_add(GTK_CONTAINER(revise.dorm_check_dialog),table);
    //宿舍号显示
    label = gtk_label_new(num);
    gtk_table_attach(GTK_TABLE(table),label,5,15,0,10,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //舍长显示
    label = gtk_label_new(captain);
    gtk_table_attach(GTK_TABLE(table),label,0,10,20,30,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //成员1
    label = gtk_label_new(member[0]);
    gtk_table_attach(GTK_TABLE(table),label,0,10,30,40,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //成员2
    label = gtk_label_new(member[1]);
    gtk_table_attach(GTK_TABLE(table),label,10,20,30,40,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //成员3
    label = gtk_label_new(member[2]);
    gtk_table_attach(GTK_TABLE(table),label,0,10,40,50,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //成员4
    label = gtk_label_new(member[3]);
    gtk_table_attach(GTK_TABLE(table),label,10,20,40,50,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //成员5
    label = gtk_label_new(member[4]);
    gtk_table_attach(GTK_TABLE(table),label,0,10,50,60,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //成员6
    label = gtk_label_new(member[5]);
    gtk_table_attach(GTK_TABLE(table),label,10,20,50,60,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //确认按钮
    button = gtk_button_new_with_label("确   认");
    gtk_table_attach(GTK_TABLE(table),button,10,20,60,70,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(button);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Revise_Dorm_Check_To_View),(gpointer)p);

    //上一步按钮
    button = gtk_button_new_with_label("返   回");
    gtk_table_attach(GTK_TABLE(table),button,0,10,60,70,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(button);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Revise_Dorm_Check_Return),NULL);

    //delete_event信号链接
    g_signal_connect(G_OBJECT(revise.dorm_check_dialog),"delete_event",G_CALLBACK(Revise_Dorm_Check_Return),NULL);

    gtk_widget_show(table);
    gtk_widget_show(revise.dorm_check_dialog);

}

//修改宿舍信息窗口
void Revise_Dorm_View(LINKLIST*p)
{
    GtkWidget *button;
    GtkWidget *label;
    GtkWidget *table;
    char dorm_num[15]={"宿舍号："};
    //创建信息填写窗口
    revise.dorm_revise_window=Create_Window(GTK_WINDOW_TOPLEVEL,"填写宿舍信息",280,200,FALSE);
    //组合表建立
    table = gtk_table_new(5,6,TRUE);
    gtk_widget_show(table);
    gtk_container_add(GTK_CONTAINER(revise.dorm_revise_window),table);
    //宿舍号
    //赋值全局变量
    strcpy(dorm_temp.num,p->dormitory.num);
    strcat(dorm_num,p->dormitory.num);
    strcpy(dorm_temp.num,p->dormitory.num);
    label = gtk_label_new(dorm_num);
    gtk_table_attach(GTK_TABLE(table),label,0,5,1,2,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //舍长姓名
     label = gtk_label_new("舍长姓名：");
    gtk_table_attach(GTK_TABLE(table),label,0,2,2,3,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    dormwidget.captain=Create_Entry(30,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),dormwidget.captain,2,5,2,3,GTK_FILL,GTK_FILL,0,0);
    //宿舍人数
    label = gtk_label_new("宿舍人数：");
    gtk_table_attach(GTK_TABLE(table),label,0,2,3,4,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    dormwidget.num=Create_Entry(1,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),dormwidget.num,2,5,3,4,GTK_FILL,GTK_FILL,0,0);
    //下一步
    button = gtk_button_new_with_label("下一步");
    gtk_table_attach(GTK_TABLE(table),button,0,5,5,6,GTK_FILL,GTK_FILL,5,0);
    g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(Revise_Dorm_Num_Check),NULL);
    gtk_widget_show(button);
    //信号链接部分
    g_signal_connect_swapped(G_OBJECT(revise.dorm_revise_window), "delete_event",G_CALLBACK(Revise_Dorm_Revise_Return), NULL);
    //显示登陆界面
    gtk_widget_show(revise.dorm_revise_window);
}

//修改_人数错误时弹窗
void Revise_Dorm_Num_Wrong_View()
{
    gint result;
    revise.dorm_num_wrong_window=gtk_message_dialog_new((GtkWindow*)revise.dorm_num_wrong_window,GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"您所输入的人数不在可接受范围内！");
    //设置对话框标题
    gtk_window_set_title(GTK_WINDOW(revise.dorm_num_wrong_window),"错误提示提示");
    //显示对话框
    //result来接受对话框的返回信息
    result=gtk_dialog_run(GTK_DIALOG(revise.dorm_num_wrong_window));
    //根据对话框返回值进行操作
    switch(result)
    {
    //当按下的是OK键时
    case    GTK_RESPONSE_OK:
        gtk_widget_destroy(revise.dorm_num_wrong_window);
        return;
    //当按下红叉时
    case    GTK_RESPONSE_DELETE_EVENT:
        gtk_widget_destroy(revise.dorm_num_wrong_window);
        return;
    }
    return;
}

//学生详细信息填写
void Revise_Dorm_Stu_Get_View()
{
    char a[30]="正在添加第";
    char b[]="个学生";
    GtkWidget *button;
    GtkWidget *label;
    GtkWidget *table;
    GSList *group=NULL;
    revise.dorm_stu_window=Create_Window(GTK_WINDOW_TOPLEVEL,"学生详细信息",350,370,TRUE);
    table = gtk_table_new(20,100,TRUE);
    //g_print("0920\n");
    gtk_container_add(GTK_CONTAINER(revise.dorm_stu_window),table);
    //显示正在添加
    strcat(a,(char*)&dorm_stu.addimf_stu_num);
    strcat(a,b);
    //g_print("0923");
    label = gtk_label_new(a);
    gtk_table_attach(GTK_TABLE(table),label,5,15,2,10,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    //姓名
    label = gtk_label_new("     姓名               :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,10,20,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    dorm_stu.name=Create_Entry(30,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),dorm_stu.name,10,20,10,20,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(dorm_stu.name);
    //性别
    //男
    dorm_temp.member[dorm_stu.addimf_stu_num-49].sex=TRUE;
    //g_print("0924");
    label = gtk_label_new("     性别               :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,20,30,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    button=gtk_radio_button_new_with_label(group," 男");
    group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    //信号链接
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Revise_Dorm_Stu_Sex_Button_Check),(gpointer)&return_num[1]);
    gtk_table_attach(GTK_TABLE(table),button,10,15,20,30,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(button);
    //女
    button = gtk_radio_button_new_with_label(group,"女");
    group = gtk_radio_button_group(GTK_RADIO_BUTTON(button));
    gtk_table_attach(GTK_TABLE(table),button,15,20,20,30,GTK_FILL,GTK_FILL,0,0);
    //信号链接
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(Revise_Dorm_Stu_Sex_Button_Check),(gpointer)&return_num[0]);
    gtk_widget_show(button);
    //班级
    label = gtk_label_new("     班级               :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,30,40,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    dorm_stu.classes=Create_Entry(30,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),dorm_stu.classes,10,20,30,40,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(dorm_stu.classes);
    //电话
    label = gtk_label_new("     电话               :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,40,50,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    dorm_stu.tel=Create_Entry(30,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),dorm_stu.tel,10,20,40,50,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(dorm_stu.tel);
    //家长姓名
    label = gtk_label_new("     家长姓名        :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,50,60,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    dorm_stu.parent_name=Create_Entry(30,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),dorm_stu.parent_name,10,20,50,60,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(dorm_stu.parent_name);
    //家长电话
    label = gtk_label_new("     家长电话       :");
    gtk_table_attach(GTK_TABLE(table),label,0,10,60,70,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(label);
    dorm_stu.parent_tel=Create_Entry(30,TRUE,TRUE);
    gtk_table_attach(GTK_TABLE(table),dorm_stu.parent_tel,10,20,60,70,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(dorm_stu.parent_tel);
    //上一步
    button = gtk_button_new_with_label("上一步");
    gtk_table_attach(GTK_TABLE(table),button,0,10,80,90,GTK_FILL,GTK_FILL,5,0);
    g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(Revise_Dorm_Stu_Goback),NULL);
    gtk_widget_show(button);
    //确定
//    g_print("00:29\n");
    if(dorm_stu.addimf_stu_num<dorm_temp.num_people)
    {
        button = gtk_button_new_with_label("下一步");
//        g_print("00:30\n");
        gtk_table_attach(GTK_TABLE(table),button,10,20,80,90,GTK_FILL,GTK_FILL,0,0);
        g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(Revise_Dorm_Stu_Check),NULL);
        gtk_widget_show(button);
    }
    else if(dorm_stu.addimf_stu_num==dorm_temp.num_people)
    {
        button = gtk_button_new_with_label("确定");
        gtk_table_attach(GTK_TABLE(table),button,10,20,80,90,GTK_FILL,GTK_FILL,0,0);
        g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(Revise_Dorm_Stu_Save),(gpointer)login.window);
        gtk_widget_show(button);
    }
    //关闭信号链接
    g_signal_connect(G_OBJECT(add.member_window),"delete_event",G_CALLBACK(Revise_Dorm_Stu_Goback),(gpointer)add.member_window);
    //显示表格
    gtk_widget_show_all(table);
    //显示窗口
    gtk_widget_show_all(revise.dorm_stu_window);
}

//修改宿舍信息存储成功弹窗
void Revise_Dorm_Save_Success()
{
    gint result;
    GtkWidget*dialog;
    dialog=gtk_message_dialog_new((GtkWindow*)revise.dorm_stu_window,GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"存储成功！");
    //设置对话框标题
    gtk_window_set_title(GTK_WINDOW(dialog),"存储提示");
    //显示对话框
    //result来接受对话框的返回信息
    result=gtk_dialog_run(GTK_DIALOG(dialog));
    //根据对话框返回值进行操作
    switch(result)
    {
    //当按下的是OK键时
    case    GTK_RESPONSE_OK:
        gtk_widget_destroy(dialog);
        gtk_widget_hide(revise.dorm_stu_window);
        gtk_widget_show(menu.window);
        return;
    //当按下红叉时
    case    GTK_RESPONSE_DELETE_EVENT:
        gtk_widget_destroy(dialog);
        gtk_widget_hide(revise.dorm_stu_window);
        gtk_widget_show(menu.window);
        return;
    }
    return;
}

/*-------------------------------------------*/

//转换类
//从登陆页面转到菜单页面
void Login_To_Menu()
{
    gtk_widget_hide(login.window);
    Menu_View();
}

//从菜单页面点击添加信息到选择楼号窗口
void Menu_To_Addimf()
{
    gtk_widget_hide(menu.window);
    Addimf_View();
}

//从信息概览楼号选择窗口返回菜单页面
void Menu_To_Overview_Return_Menu()
{
    gtk_widget_hide(menu.To_Overview_Window);
    gtk_widget_show(menu.window);
}

//从信息添加楼号选择窗口返回菜单页面
void Addimf_Choose_Return()
{
    gtk_widget_hide(add.choose_window);
    gtk_widget_show(menu.window);
}

//从信息添加楼号选择窗口到宿舍大致信息填写窗口
void Addimf_Choose_To_Overview()
{
    g_print("%d号楼\n",add.number);
    gtk_widget_hide(add.choose_window);
    Addimf_Over_View();
}

//从添加大致宿舍信息窗口返回菜单页面
void Addimf_Overview_return()
{
    gtk_widget_hide(add.over_window);
    gtk_widget_show(menu.window);
}

//从添加成员信息窗口返回菜单页面
void Addimf_Stu_return()
{
    gtk_widget_hide(add.member_window);
    gtk_widget_show(menu.window);
}

//从菜单到查询
void Menu_To_Search()
{
    gtk_widget_hide(menu.window);
    Search_Choose_Menu_View();
}

//从查询菜单到查询
void Search_Menu_To_Search()
{
    gtk_widget_hide(searchview.choose_menu_window);
  //从参数判断创建哪个窗口
    if(!searchparameter.dorm_or_stu)
        Search_Choose_Stu_View();
    else
        Search_Choose_Dorm_View();
}
//宿舍菜单到宿舍结果
void Dorm_Menu_To_Dorm()
{
    DDATA *head,*p;
    //是否查到
    int flag=0;
    switch(searchparameter.num_dorm)
    {
        case    1:strcpy(menu.filename,"Overview_1");   break;
        case    2:strcpy(menu.filename,"Overview_2");   break;
        case    3:strcpy(menu.filename,"Overview_3");   break;
        case    4:strcpy(menu.filename,"Overview_4");   break;
    }
    head = Read_Ddata(menu.filename);
    for(p=head->next;p!=NULL;p=p->next)
    {
        if(!(strcmp(p->num,gtk_entry_get_text(GTK_ENTRY(searchparameter.dorm_number)))))
            {
            flag =1;
            memcpy(&ddata,p,sizeof(DDATA));
            break;
            }
    }
    if(flag)
    {
        Search_Dorm_View();
    }
    else
    {
        //未查到窗口
    }


}
//学生菜单到学生
void Stu_Menu_To_Stu()
{
    g_print("转到\n");
    int i,j,k=0;
    char *filename[4]={"Data_1","Data_2","Data_3","Data_4"};

    for(i=0;i<4;i++)
    {
        head1 = Create_Linklist(filename[i]);
        if(head1==NULL)
            continue;
        else
            //g_print("head \n");

        p1=head1;
        while(p1!=NULL)
        {
            for(j=0;j<6;j++)
            {
                //g_print("指针p1%s\n",p1->dormitory.member[j].name);
                if(!(strcmp(p1->dormitory.member[j].name,gtk_entry_get_text(GTK_ENTRY(searchparameter.stu_name)))))
                {
//                    g_print("以找到\n");
//                    g_print("%d  %d\n",p1,p1->next);
                    stu_search[k]=(STU_IMF*)malloc(sizeof(STU_IMF));
                    memcpy(stu_search[k],&p1->dormitory.member[j],sizeof(STU_IMF));
                    k++;
                    g_print("%s\n",stu_search[k-1]->name);
                }
            }
            p1=p1->next;
        }
        Linklist_Free(head1);
    }
    //隐藏x
    gtk_widget_hide(searchview.choose_stu_window);
    Search_Stu_View() ;
}

//从菜单到修改菜单
void Menu_To_Revise()
{
    gtk_widget_hide(menu.window);
    Revise_Choose_View();
}

//从修改菜单返回菜单
void Revise_Choose_Return()
{
    gtk_widget_hide(revise.choose_menu_window);
    gtk_widget_show(menu.window);
}

//从修改菜单到获取信息
void Revise_Menu_To_Get()
{
  //从参数判断创建哪个窗口
    if(revise_imf.dorm_or_stu)
        Revise_Menu_To_Dorm_Get();
    else
        Revise_Menu_To_Stu_Get();
}

//从修改菜单到宿舍信息录入窗口
void Revise_Menu_To_Dorm_Get()
{
    gtk_widget_hide(revise.choose_menu_window);
    Revise_Dorm_Get_View();
}

//从修改菜单到学生信息录入窗口
void Revise_Menu_To_Stu_Get()
{
    gtk_widget_hide(revise.choose_menu_window);
    Revise_Stu_Get_View();
}

//从修改宿舍信息录入返回修改菜单
void Revise_Dorm_Get_Return()
{
    gtk_widget_hide(revise.dorm_get_window);
    gtk_widget_show(revise.choose_menu_window);
}

//从修改学生信息录入返回修改菜单
void Revise_Stu_Get_Return()
{
    gtk_widget_hide(revise.stu_get_window);
    gtk_widget_show(revise.choose_menu_window);
}

//修改_从宿舍信息确认窗口返回宿舍信息录入窗口
void Revise_Dorm_Check_Return()
{
    gtk_widget_hide(revise.dorm_check_dialog);
    gtk_widget_show(revise.dorm_get_window);
}

//修改_从宿舍信息确认窗口到宿舍信息填写窗口
void Revise_Dorm_Check_To_View(GtkWidget*widget,gpointer gdata)
{
    gtk_widget_hide(revise.dorm_check_dialog);
    //g_print("got it\n");
    Revise_Dorm_View((LINKLIST*)gdata);
}

//从查找返回菜单
void Search_Choose_Menu_Return()
{
    //gtk_widget_hide(searchview.choose_menu_window);
    gtk_widget_destroy(searchview.choose_menu_window);
    gtk_widget_show(menu.window);
}

//修改_从成员详细信息返回宿舍概览信息填写窗口
void Revise_Dorm_Stu_Goback()
{
    gtk_widget_hide(revise.dorm_stu_window);
    gtk_widget_show(revise.dorm_revise_window);
}

//从搜索学生返回
void Search_Stu_Return()
{
    gtk_widget_hide(searchview.stu_window);
    gtk_widget_show(searchview.choose_stu_window);
}

//从搜索宿舍返回
void Search_Dorm_Return()
{
    gtk_widget_hide(searchview.dorm_window);
    gtk_widget_show(searchview.choose_dorm_window);
}

//从搜索学生的选择页面返回
void Search_Choose_Stu_Return()
{
    gtk_widget_hide(searchview.choose_stu_window);
    gtk_widget_show(searchview.choose_menu_window);
}

//从搜索宿舍的选择页面返回
void Search_Choose_Dorm_Return()
{
    gtk_widget_hide(searchview.choose_dorm_window);
    gtk_widget_show(searchview.choose_menu_window);
}

//修改_从宿舍大致信息修改页面返回
void Revise_Dorm_Revise_Return()
{
    gtk_widget_hide(revise.dorm_revise_window);
    gtk_widget_show(revise.dorm_check_dialog);
}

/*-------------------------------------------*/

//控制类函数
//宿舍概览_选择列返回函数
void select_row_callback(GtkWidget *widget,gint row,gint column,GdkEventButton *event,gpointer data)
{
    gchar * da[8];
    int i;
    DDATA *head,*p;
    //在终端打印选择的列作为辅助
    g_print("%d\n",row);
    for(i=0;i<8;i++)
    {
        da[i]=(gchar *)malloc(sizeof(gchar)*30);
    }
    //根据所选择的列进行操作
    switch(row)
    {
        case 0:
            gtk_clist_freeze(GTK_CLIST(overview.clist));
            gtk_clist_clear(GTK_CLIST(overview.clist));
            //读取数据
            head = Read_Ddata(menu.filename);
            //排序
            head = Sort_Ddata(head,overview.flag%2);
            g_print("在这%d\n",overview.flag);
            overview.flag++;
            //重新将数据加入分栏
            for(p=head->next;p!=NULL;p=p->next)
            {
                strcpy(da[0],p->num);
                strcpy(da[1],p->captain);
                strcpy(da[2],p->member[0]);
                strcpy(da[3],p->member[1]);
                strcpy(da[4],p->member[2]);
                strcpy(da[5],p->member[3]);
                strcpy(da[6],p->member[4]);
                strcpy(da[7],p->member[5]);
                gtk_clist_prepend(GTK_CLIST(overview.clist),da);
            }
            gtk_clist_thaw(GTK_CLIST(overview.clist));
            break;
        default:;
    }
}

//宿舍概览_根据选择的楼号改变变量值
void Menu_To_Overview_Button_Check(GtkWidget*widget,gpointer number)
{
    //将signal给的信号值存为gint型
    gint flag=0;
    flag=*(int*)number;
    //根据信号值对menu.filename进行命名
    switch(flag)
    {
        case    1:strcpy(menu.filename,"Overview_1");   break;
        case    2:strcpy(menu.filename,"Overview_2");   break;
        case    3:strcpy(menu.filename,"Overview_3");   break;
        case    4:strcpy(menu.filename,"Overview_4");   break;
    }
    return;
}

//宿舍概览_根据变量值决定打开的文件
gchar* Menu_To_Overview_File(GtkWidget*widget,gpointer gdata)
{
    g_print("%s\n",menu.filename);
    return menu.filename;
}

//登陆检查
void Login_Check(GtkWidget* widget,gpointer data)
{
    FILE *fp;
    SDATA *head ,*p ,*da;
    char user[30]="\0";
    char password[30]="\0";
    char captcha[5]="\0";
    //几个数据的状态值
    gint usernametime=0,passwordtime=0,captchatime=0;
    //从文件中读取账号信息到链表
    head = (SDATA*)malloc(sizeof(SDATA));
    head->next=NULL;
    p=head;
    fp=fopen("sdata","r");
    da=(SDATA*)malloc(sizeof(SDATA));
    while(fread(da, sizeof(SDATA), 1, fp) != 0)
    {
            //在终端打印信息
            g_print("%s %s\n",da->user,da->password);
            p->next=da;
            p=da;
            da=(SDATA*)malloc(sizeof(SDATA));
    }
    g_print("取信息成功\n");
    p->next=NULL;
    fclose(fp);
    //将窗口内输入的信息取出
    strcpy(user,gtk_entry_get_text(GTK_ENTRY(login.user)));
    strcpy(password,gtk_entry_get_text(GTK_ENTRY(login.password)));
    strcpy(captcha,gtk_entry_get_text(GTK_ENTRY(login.identify_code)));
    //在终端打印读出信息便于确认
    g_print("%s %s %s %s\n",user,password,captcha,login.captcha);
    //从链表头开始验证账号密码
    for(p=head->next;p!=NULL;p=p->next)
    {
        g_print("%s %s\n",p->user,p->password);
        //验证信息
        if(!strcmp(user,p->user))
        {
            //改变用户名状态值
            usernametime=1;
            if(!strcmp(password,p->password))
            {
                //改变密码状态值
                passwordtime=1;
                if(!strcmp(captcha,login.captcha))
                {
                    // 信息正确
                    //改变验证码状态值
                    captchatime=1;
                    //终端打印信息
                    g_print("Login.\n");
                    //释放整个链表
                    da=head;
                    for(p=head->next;p!=NULL;p=p->next)
                    {
                        free(da);
                        da=p;
                    }
                    //改变登陆状态值
                    login.flag=1;
                    //跳出循环
                    break;
                }
            }
        }
    }
    //没找到用户名时
    if(!usernametime)
    {
        login.flag=5;
    }
    //没找到密码时
    else    if(!passwordtime)
    {
        login.flag=2;
        login.errortime++;
    }
    //验证码不对时
    else    if(!captchatime)
    {
        login.flag=3;
    }

    //将状态值重置
    usernametime=0;
    passwordtime=0;
    captchatime=0;

    //密码错误超过3次状态值变为4
    if(login.errortime==3)
        login.flag=4;

    switch(login.flag)
    {
        //状态值为1时，登陆成功
        case    1:Login_To_Menu();  break;
        //状态值为2时，密码错误
        case    2:Login_Password_Wrong();   break;
        //状态值为3时，验证码错误
        case    3:Login_Captcha_Wrong();    break;
        //状态值为4时，密码错误次数超过3次，退出软件
        case    4:Login_Error();    break;
        //状态值为5时，账户不存在
        case    5:Login_Username_Wrong();   break;
    }
    return;
}

//信息添加_根据选择的楼号改变变量值
void Menu_To_Addimf_Button_Check(GtkWidget*widget,gpointer number)
{
    add.number=*(int*)number;
    return;
}

//将所填写的大致信息存入变量
void Addimf_Overview_Save()
{
    strcpy(d_imf.num,gtk_entry_get_text(GTK_ENTRY(Addoverimf.num)));
    strcpy(d_imf.captain,gtk_entry_get_text(GTK_ENTRY(Addoverimf.captain)));
    strcpy(&d_imf.num_people,gtk_entry_get_text(GTK_ENTRY(Addoverimf.num_people)));
    g_print("d_num:%s d_capt:%s d_num_p:%c\n",d_imf.num,d_imf.captain,d_imf.num_people);
    //如果人数输入不在范围内
    if(d_imf.num_people<49 || d_imf.num_people>54)
    {
        //显示提示信息窗口
        Addimf_Overview_Num_Wrong_View();
        return;
    }
    else
    {
        //人数初始化
        stu_info.addimf_stu_num=49;
        //显示隐藏
        gtk_widget_hide(add.over_window);
        Addimf_Stu_View();
    }
}

//详细学生信息检查
void Addimf_Stu_Check(GtkWidget *widget,gpointer data)
{
    //存储姓名
    strcpy(d_imf.member[stu_info.addimf_stu_num-49].name,gtk_entry_get_text(GTK_ENTRY(stu_info.name)));
    //班级
    strcpy(d_imf.member[stu_info.addimf_stu_num-49].classes,gtk_entry_get_text(GTK_ENTRY(stu_info.classes)));
    //电话
    strcpy(d_imf.member[stu_info.addimf_stu_num-49].tel,gtk_entry_get_text(GTK_ENTRY(stu_info.tel)));
    //家长姓名
    strcpy(d_imf.member[stu_info.addimf_stu_num-49].parent_name,gtk_entry_get_text(GTK_ENTRY(stu_info.parent_name)));
    //家长电话
    strcpy(d_imf.member[stu_info.addimf_stu_num-49].parent_tel,gtk_entry_get_text(GTK_ENTRY(stu_info.parent_tel)));
    //更改变量
    stu_info.addimf_stu_num++;

    //销毁
    gtk_widget_destroy(add.member_window);
    Addimf_Stu_View();
    }

//详细信息性别检查
void Stu_Sex_Button_Check(GtkWidget *widget,gpointer data)
{
    if(*(int*)data)
        d_imf.member[stu_info.addimf_stu_num-49].sex=TRUE;
    else
        d_imf.member[stu_info.addimf_stu_num-49].sex=FALSE;
}

//详细信息保存最终版
void Addimf_Stu_Save(GtkWidget *widget,gpointer gdata)
{
    gboolean flag;
    //存储姓名
    strcpy(d_imf.member[stu_info.addimf_stu_num-49].name,gtk_entry_get_text(GTK_ENTRY(stu_info.name)));
    //班级
    strcpy(d_imf.member[stu_info.addimf_stu_num-49].classes,gtk_entry_get_text(GTK_ENTRY(stu_info.classes)));
    //电话
    strcpy(d_imf.member[stu_info.addimf_stu_num-49].tel,gtk_entry_get_text(GTK_ENTRY(stu_info.tel)));
    //家长姓名
    strcpy(d_imf.member[stu_info.addimf_stu_num-49].parent_name,gtk_entry_get_text(GTK_ENTRY(stu_info.parent_name)));
    //家长电话
    strcpy(d_imf.member[stu_info.addimf_stu_num-49].parent_tel,gtk_entry_get_text(GTK_ENTRY(stu_info.parent_tel)));
    flag=Addimf_Save();
    if(flag)
    {
        //存储成功弹窗
        Addimf_Save_Success();
    }
    else
    {
        //存储失败弹窗
        Addimf_Save_Error();
    }

    //重置全局变量
    Init_d_imf();

    gtk_widget_hide(add.member_window);
    gtk_widget_show(menu.window);

}


//控制成员信息添加中的"上一步"按钮
void Addimf_Stu_Goback()
{
    if(stu_info.addimf_stu_num==49)
    {
        gtk_widget_destroy(add.member_window);
        gtk_widget_show(add.over_window);
    }
    else
    {
        gtk_widget_destroy(add.member_window);
        stu_info.addimf_stu_num--;
        Addimf_Stu_View();
    }
}

//重置d_imf全局变量
void Init_d_imf()
{
    int i;
    memset(d_imf.num,0,sizeof(d_imf.num));
    memset(d_imf.captain,0,sizeof(d_imf.captain));
    d_imf.num_people=0;
    for(i=0;i<6;i++)
    {
        memset(d_imf.member[i].name,0,sizeof(d_imf.member[i].name));
        memset(d_imf.member[i].classes,0,sizeof(d_imf.member[i].classes));
        memset(d_imf.member[i].tel,0,sizeof(d_imf.member[i].tel));
        d_imf.member[i].sex=TRUE;
        memset(d_imf.member[i].parent_name,0,sizeof(d_imf.member[i].parent_name));
        memset(d_imf.member[i].parent_tel,0,sizeof(d_imf.member[i].parent_tel));
    }
    return;
}

//将添加信息存入data和overview文件
gboolean Addimf_Save()
{
    FILE *fp;
    char datafile[10]={"Data_"},overfile[15]={"Overview_"},number;
    int i;
    g_print("Save\n");
    //获取楼号
    number=add.number+48;
    //将楼号赋给文件名
    strcat(datafile,&number);
    strcat(overfile,&number);

    g_print("%s %s\n",datafile,overfile);
    //将数据存储到datafile
    fp=fopen(datafile,"a+");
    //打开失败
    if(!fp)
        return FALSE;
    fwrite(&d_imf,sizeof(D_IMF),1,fp);
    fclose(fp);
    g_print("DataSave\n");

    //将数据存储到overfile
    fp=fopen(overfile,"a+");
    //打开失败
    if(!fp)
        return FALSE;
    //将详细数据赋到概览数据
    strcpy(ddata.num,d_imf.num);
    strcpy(ddata.captain,d_imf.captain);
    for(i=0;i<6;i++)
    {
        strcpy(ddata.member[i],d_imf.member[i].name);
    }
    g_print("5%s\n",d_imf.member[4].name);
    ddata.next=NULL;
    g_print("%s%s%s%s%s%s%s%s\n",ddata.num,ddata.captain,ddata.member[0],ddata.member[1],ddata.member[2],ddata.member[3],ddata.member[4],ddata.member[5]);
    fwrite(&ddata,sizeof(DDATA),1,fp);
    fclose(fp);
    //储存成功返回TRUE
    return TRUE;
}

//释放链表
void Linklist_Free(LINKLIST*head)
{
    LINKLIST*temp1,*temp2;
    temp1=head->next;
    temp2=temp1->next;
    while(temp2!=NULL)
    {
        free(temp1);
        temp1=temp2;
        temp2=temp1->next;
    }
    free(head);
}

//查询菜单检查
void Search_Choose_Menu_Button_Check(GtkWidget * widget,gpointer data)
{
    if(!*(int*)data)
    {
        //选择学生
        searchparameter.dorm_or_stu=FALSE;
    }
    else
    {
        //选择宿舍
        searchparameter.dorm_or_stu=TRUE;
    }
}

//查询_楼号检查
void Dorm_Menu_To_Search_Button_Check(GtkWidget*widget,gpointer data)
{
    switch(*(int *)data)
    {
        case 1:searchparameter.num_dorm=1;break;
        case 2:searchparameter.num_dorm=2;break;
        case 3:searchparameter.num_dorm=3;break;
        case 4:searchparameter.num_dorm=4;break;
    }
    g_print("选择了%d号楼\n",searchparameter.num_dorm);
}

//修改菜单检查
void Revise_Choose_Menu_Button_Check(GtkWidget * widget,gpointer data)
{
    if(*(int*)data)
    {
        //选择学生
        revise_imf.dorm_or_stu=TRUE;
    }
    else
    {
        //选择宿舍
        revise_imf.dorm_or_stu=FALSE;
    }
}

//修改宿舍信息录入楼号检查
void Revise_Dorm_Get_Button_Check(GtkWidget*widget,gpointer gdata)
{
    switch(*(int*)gdata)
    {
        case 1:revise_imf.num_dorm=1;   break;
        case 2:revise_imf.num_dorm=2;   break;
        case 3:revise_imf.num_dorm=3;   break;
        case 4:revise_imf.num_dorm=4;   break;
    }
}

//修改_根据选择的楼号改变变量值
void Revise_Filename()
{
    //根据信号值对revise.filename进行命名
    switch(revise_imf.num_dorm)
    {
        case    1:
            strcpy(revise_imf.datafile,"Data_1");
            strcpy(revise_imf.overfile,"Overview_1");
//            g_print("%s\n",revise_imf.datafile);
            break;
        case    2:
            strcpy(revise_imf.datafile,"Data_2");
            strcpy(revise_imf.overfile,"Overview_2");
            break;
        case    3:
            strcpy(revise_imf.datafile,"Data_3");
            strcpy(revise_imf.overfile,"Overview_3");
            break;
        case    4:
            strcpy(revise_imf.datafile,"Data_4");
            strcpy(revise_imf.overfile,"Overview_4");
            break;
    }
    return;
}

//查找要修改的宿舍
LINKLIST* Revise_Dorm_Get_Search()
{
    LINKLIST *head,*temp1,*temp2;
    //获取宿舍号
    char num[4];
    memset(num,0,sizeof(num));
    strcpy(num,gtk_entry_get_text(GTK_ENTRY(revise.dorm_num)));
    //从文件中读取数据
    head=Create_Linklist(revise_imf.datafile);
    if(head==NULL)
    {
        g_print("NULL head.\n");
        return NULL;
    }
    temp1=head;
    temp2=temp1->next;
    while(temp1!=NULL)
    {
        if(!strcmp(num,temp1->dormitory.num))
        {
            g_print("Found it.\n");
            revise_imf.dorm_head=head;
            return temp1;
        }
        else
        {
            temp1=temp2;
            temp2=temp1->next;
        }
    }
    g_print("Not Find.\n");
    return NULL;
}

//修改_将查询到的宿舍信息读出，并询问是否修改
void Revise_Dorm_Check()
{
    LINKLIST *p;
    Revise_Filename();
    p=Revise_Dorm_Get_Search();
    if(!p)
    {
        g_print("Didn't find it.\n");
    }
    else
    {
        g_print("%s %s %c\n",p->dormitory.num,p->dormitory.captain,p->dormitory.num_people);
        dorm_temp=p->dormitory;
        //显示确认窗口
        gtk_widget_hide(revise.dorm_get_window);
        revise_imf.datap=p;
        Revise_Dorm_Check_View(p);
    }
}

//修改_检测宿舍修改人数
void Revise_Dorm_Num_Check()
{
    //将数据存入
    strcpy(dorm_temp.captain,gtk_entry_get_text(GTK_ENTRY(dormwidget.captain)));
    strcpy(&dorm_temp.num_people,(char*)gtk_entry_get_text(GTK_ENTRY(dormwidget.num)));
    //g_print("d_num:%s d_capt:%s d_num_p:%c\n",d_imf.num,d_imf.captain,d_imf.num_people);
    //如果人数输入不在范围内
    if(dorm_temp.num_people<'1' || dorm_temp.num_people>'6')
    {
        //显示提示信息窗口
        Revise_Dorm_Num_Wrong_View();
        return;
    }
    else
    {
        //人数初始化
        dorm_stu.addimf_stu_num=49;
//        g_print("00:27\n");
        //显示隐藏
        gtk_widget_hide(revise.dorm_revise_window);
        //学生详细信息填写
        Revise_Dorm_Stu_Get_View();
    }
}

//修改学生搜索
void Revise_Stu_To_Get()
{
    int i,j,k=0;
    char *filename[4]={"Data_1","Data_2","Data_3","Data_4"};

    for(i=0;i<4;i++)
    {
        head1 = Create_Linklist(filename[i]);
        if(head1==NULL)
            continue;
        else
            //g_print("head \n");

        p1=head1;
        while(p1!=NULL)
        {
            for(j=0;j<6;j++)
            {
                //g_print("指针p1%s\n",p1->dormitory.member[j].name);
                if(!(strcmp(p1->dormitory.member[j].name,gtk_entry_get_text(GTK_ENTRY(revise.stu_name)))))
                {
                    g_print("OK\n");
                    stu_search[k]=(STU_IMF*)malloc(sizeof(STU_IMF));
                    memcpy(stu_search[k],&p1->dormitory.member[j],sizeof(STU_IMF));
                    g_print("OK2\n");
                    Revise_Stu_Isok(NULL,(gpointer)&return_num[k]);
                     g_print("OK3\n");
                    k++;
                }
            }
            p1=p1->next;
        }
        //释放链表
        Linklist_Free(head1);
    }
}

//修改_宿舍成员信息录入检查
void Revise_Dorm_Stu_Check()
{
    //存储姓名
    strcpy(dorm_temp.member[dorm_stu.addimf_stu_num-49].name,gtk_entry_get_text(GTK_ENTRY(dorm_stu.name)));
    //班级
    strcpy(dorm_temp.member[dorm_stu.addimf_stu_num-49].classes,gtk_entry_get_text(GTK_ENTRY(dorm_stu.classes)));
    //电话
    strcpy(dorm_temp.member[dorm_stu.addimf_stu_num-49].tel,gtk_entry_get_text(GTK_ENTRY(dorm_stu.tel)));
    //家长姓名
    strcpy(dorm_temp.member[dorm_stu.addimf_stu_num-49].parent_name,gtk_entry_get_text(GTK_ENTRY(dorm_stu.parent_name)));
    //家长电话
    strcpy(dorm_temp.member[dorm_stu.addimf_stu_num-49].parent_tel,gtk_entry_get_text(GTK_ENTRY(dorm_stu.parent_tel)));
    //更改变量
    dorm_stu.addimf_stu_num++;

    //销毁
    gtk_widget_destroy(revise.dorm_stu_window);
    Revise_Dorm_Stu_Get_View();
    }

//修改_宿舍详细信息性别检查
void Revise_Dorm_Stu_Sex_Button_Check(GtkWidget *widget,gpointer data)
{
    if(*(int*)data)
        dorm_temp.member[dorm_stu.addimf_stu_num-49].sex=TRUE;
    else
        dorm_temp.member[dorm_stu.addimf_stu_num-49].sex=FALSE;
}

//修改_宿舍详细信息保存最终版
void Revise_Dorm_Stu_Save(GtkWidget *widget,gpointer gdata)
{
    gboolean flag;
    //存储姓名
    strcpy(dorm_temp.member[dorm_stu.addimf_stu_num-49].name,gtk_entry_get_text(GTK_ENTRY(dorm_stu.name)));
    g_print("22:55  %s\n",dorm_temp.member[0].name);
    //班级
    strcpy(dorm_temp.member[dorm_stu.addimf_stu_num-49].classes,gtk_entry_get_text(GTK_ENTRY(dorm_stu.classes)));
    //电话
    strcpy(dorm_temp.member[dorm_stu.addimf_stu_num-49].tel,gtk_entry_get_text(GTK_ENTRY(dorm_stu.tel)));
    //家长姓名
    strcpy(dorm_temp.member[dorm_stu.addimf_stu_num-49].parent_name,gtk_entry_get_text(GTK_ENTRY(dorm_stu.parent_name)));
    //家长电话
    strcpy(dorm_temp.member[dorm_stu.addimf_stu_num-49].parent_tel,gtk_entry_get_text(GTK_ENTRY(dorm_stu.parent_tel)));
    flag=Revise_Dorm_Save();
    g_print("%d\n",flag);
    if(flag)
    {
        //存储成功弹窗
        Revise_Dorm_Save_Success();
    }
    else
    {
        //存储失败弹窗
        Addimf_Save_Error();
    }

    //重置全局变量
    Init_d_imf();

    gtk_widget_hide(add.member_window);
    gtk_widget_show(menu.window);

}

//将宿舍修改信息存入data和overview文件
gboolean Revise_Dorm_Save()
{
    FILE *fp;
    LINKLIST*temp1;
    DDATA *over_temp1;
    char datafile[30]={"Data_"},overfile[30]={"Overview_"};
    int i;
    g_print("Save\n");
    switch(revise_imf.num_dorm)
    {
        case 1:
            strcpy(datafile,"Data_1");
            strcpy(overfile,"Overview_1");
            break;
        case 2:
            strcpy(datafile,"Data_2");
            strcpy(overfile,"Overview_2");
            break;
        case 3:
            strcpy(datafile,"Data_3");
            strcpy(overfile,"Overview_3");
            break;
        case 4:
            strcpy(datafile,"Data_4");
            strcpy(overfile,"Overview_4");
            break;
    }
    g_print("%s %s\n",datafile,overfile);
    //将修改信息替换入链表
    strcpy(revise_imf.datap->dormitory.num,dorm_temp.num);
    strcpy(revise_imf.datap->dormitory.captain,dorm_temp.captain);
    strcpy(&revise_imf.datap->dormitory.num_people,&dorm_temp.num_people);
//    g_print("%s   %s\n",revise_imf.datap->dormitory.num,revise_imf.datap->dormitory.captain);

    for(i=0;i<6;i++)
    {
        revise_imf.datap->dormitory.member[i].sex=1;
        memset(revise_imf.datap->dormitory.member[i].name,0,sizeof(revise_imf.datap->dormitory.member[i].name));
        memset(revise_imf.datap->dormitory.member[i].classes,0,sizeof(revise_imf.datap->dormitory.member[i].classes));
        memset(revise_imf.datap->dormitory.member[i].parent_name,0,sizeof(revise_imf.datap->dormitory.member[i].parent_name));
        memset(revise_imf.datap->dormitory.member[i].parent_tel,0,sizeof(revise_imf.datap->dormitory.member[i].parent_tel));
        memset(revise_imf.datap->dormitory.member[i].tel,0,sizeof(revise_imf.datap->dormitory.member[i].tel));
    }
//    g_print("22:53%s\n",dorm_temp.member[0].name);
    for(i=0;i<dorm_temp.num_people-48;i++)
    {
        strcpy(revise_imf.datap->dormitory.member[i].name,dorm_temp.member[i].name);
        strcpy(revise_imf.datap->dormitory.member[i].classes,dorm_temp.member[i].classes);
        revise_imf.datap->dormitory.member[i].sex=dorm_temp.member[i].sex;
        strcpy(revise_imf.datap->dormitory.member[i].tel,dorm_temp.member[i].tel);
        strcpy(revise_imf.datap->dormitory.member[i].parent_name,dorm_temp.member[i].parent_name);
        strcpy(revise_imf.datap->dormitory.member[i].parent_name,dorm_temp.member[i].parent_tel);
        //g_print("%d\n",i);
    }
//    g_print("%d\n",revise_imf.datap);
//    g_print("2019");
    //将数据存储到datafile
    fp=fopen(datafile,"w");
    //打开失败
    if(!fp)
        return FALSE;
//    temp_head=revise_imf.dorm_head;
//    g_print("%s    %s\n",revise_imf.dorm_head->next->dormitory.num,revise_imf.dorm_head->next->dormitory.captain);
    temp1=revise_imf.dorm_head->next;
//    g_print("%d\n%d\n",temp1->next,temp1);
//    g_print("%s %s\n",temp1->dormitory.num,temp1->dormitory.captain);
    while(temp1!=NULL)
    {
//        g_print("%s\n",temp1->dormitory.member[0].name);
        fwrite(&temp1->dormitory,sizeof(D_IMF),1,fp);
//        g_print("2119\n");
        g_print("%s %s \n",temp1->dormitory.num,temp1->dormitory.captain);
        temp1=temp1->next;

    }
    fclose(fp);
    g_print("DataSave\n");


    //将数据存储到overfile
    revise_imf.overviewp=Revise_Dorm_Stu_Search(overfile);
//    g_print("23:03 %d\n",revise_imf.overviewp);
    strcpy(revise_imf.overviewp->captain,dorm_temp.captain);
    strcpy(revise_imf.overviewp->num,dorm_temp.num);
//    g_print("23:05 %s  %s\n",revise_imf.overviewp->captain,revise_imf.overviewp->num);
    for(i=0;i<6;i++)
    {
        memset(revise_imf.overviewp->member[i],0,sizeof(char)*30);
    }
    for(i=0;i<dorm_temp.num_people-48;i++)
    {
        strcpy(revise_imf.overviewp->member[i],dorm_temp.member[i].name);
        g_print("23:06  %s\n",revise_imf.overviewp->member[i]);
    }
    fp=fopen(overfile,"w+");
//    //打开失败
//    if(!fp)
//        return FALSE;
    g_print("5\n");
    over_temp1=revise_imf.overview_head->next;
//    g_print("23:09  %d\n",over_temp1);
    //over_temp2=over_temp1->next;
    if(over_temp1!=NULL)
        g_print("你妈逼\n");
    while(over_temp1!=NULL)
    {
        g_print("23:10 %s\n",over_temp1->member[0]);
        fwrite(over_temp1,sizeof(DDATA),1,fp);
        over_temp1=over_temp1->next;
    }
    g_print("2105\n");
    //g_print("%s%s%s%s%s%s%s%s\n",ddata.num,ddata.captain,ddata.member[0],ddata.member[1],ddata.member[2],ddata.member[3],ddata.member[4],ddata.member[5]);
    fclose(fp);
    //储存成功返回TRUE
    return TRUE;
}

//修改_在overview文件中找到需要的信息位置
DDATA* Revise_Dorm_Stu_Search(char*filename)
{
    DDATA*temp1;
    revise_imf.overview_head=Read_Ddata(filename);
    temp1=revise_imf.overview_head;
//    temp2=temp1->next;
    while(temp1!=NULL)
    {
        if(!strcmp(temp1->num,dorm_temp.num))
            return temp1;
        //temp1=temp2;
        temp1=temp1->next;
    }
    //g_print("没找到\n");
    return NULL;
}

int main (int argc, char *argv[])
{
    //初始化gtk
    gtk_init(&argc,&argv);
    //进入登陆界面
    Login_View();
    //gtk主循环
    gtk_main();
    return 0;
}
