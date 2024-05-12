//
// Created by XingCChenSAMA on 2024/4/8.
//
#include "..\\include\\Product_Management_System.h"
#define N 100
products products_list;
emp emp_list;
list_temp listTemp;
vip vip_list;
products pro_temp[N];
emp emp_temp[N];
list_temp listTemps[N];
vip vip_temp[N];
//鸡汤
void jitang(){
    int i=rand()%11+1;
    if(i==1)
    {
        printf("工作激励着我们不断前进，每一次的努力都是为了实现自己的目标和梦想。\n");
    }
    if(i==2)
    {
        printf("每一次努力都是对成功的靠近，让我们一起激发工作正能量，勇往直前。\n");
    }
    if(i==3)
    {
        printf("不要等待机会，而是要创造机会。工作不仅仅是完成任务，更是要超越自我，追求卓越。\n");
    }
    if(i==4)
    {
        printf("努力工作，换来的是成功的喜悦和自豪的荣誉。\n");
    }
    if(i==5)
    {
        printf("勤奋工作，展现才华，创造美好未来。\n");
    }
    if(i==6)
    {
        printf("工作激发智慧，创新铸就辉煌。\n");
    }
    if(i==7)
    {
        printf("谁愿意脚踏实地认真地工作，谁就能做出很多成绩，就能超群出众。\n");
    }
    if(i==8)
    {
        printf("每一份工作都是一次机会，每一次机会都值得全力以赴。\n");
    }
    if(i==9)
    {
        printf("我们应该珍惜这份工作，用激情和汗水创造出更多的成果，让自己和团队更上一层楼。\n");
    }
    if(i==10)
    {
        printf("工作中，不要害怕失败，要学会从失败中汲取经验和教训。\n");
    }

}

//库存提醒
void reminder(){
    FILE *fp;
    int flag_0=0,flag_1=0;
    int n_year,n_month,n_day;
    int diff;
    while(1){
        //获取现在时间
        time_t Curtime = time(NULL);
        struct tm *time_now = localtime(&Curtime);
        struct tm date1={0};
        struct tm date2={0};
        //把当前时间给到date1
        date1.tm_year=time_now->tm_year;
        date1.tm_mon=time_now->tm_mon;
        date1.tm_mday=time_now->tm_mday;
        //计算当前时间的时间戳
        time_t a= mktime(&date1);

        system("cls");
        printf("  ______          __           _          _   __      __           \n"
               " /_  __/___  ____/ /___ ___  _( )_____   / | / /___  / /____  _____\n"
               "  / / / __ \\/ __  / __ `/ / / /// ___/  /  |/ / __ \\/ __/ _ \\/ ___/\n"
               " / / / /_/ / /_/ / /_/ / /_/ / (__  )  / /|  / /_/ / /_/  __(__  ) \n"
               "/_/  \\____/\\__,_/\\__,_/\\__, / /____/  /_/ |_/\\____/\\__/\\___/____/  \n"
               "                      /____/                                       \n");
        printf("----------------------------------------------------------------\n");

        //库存告急提醒

        if((fp= fopen("..\\data\\products_data.txt","r"))==NULL){
            break;
        }

        fread(&products_list, sizeof(products ),1,fp);
        while(!feof(fp)){
            if(products_list.num<10){
                printf("%s\t%s <<<当前商品库存即将售罄(当前%d件)，请及时补货！！！\n",
                       products_list.id,products_list.name,products_list.num);
                flag_0=1;
            }
            else if(products_list.num<50){
                printf("%s\t%s <<<当前商品已不足50件(当前%d件)，请及时补货！！！\n",
                       products_list.id,products_list.name,products_list.num);
                flag_0=1;
            }
            else if(products_list.num<100){
                printf("%s\t%s <<<当前商品已不足100件(当前%d件)，请及时补货！！！\n",
                       products_list.id,products_list.name,products_list.num);
                flag_0=1;
            }

            fread(&products_list, sizeof(products ),1,fp);
        }
        fclose(fp);

        if(flag_0 != 1){
            printf("暂无库存不足信息!!!\n");
        }
        else{
            printf("---------------------------------\n");
            printf("库存通知输出完毕!!!\n");
        }
        system("pause");
        system("cls");

        printf("  ______          __           _          _   __      __           \n"
               " /_  __/___  ____/ /___ ___  _( )_____   / | / /___  / /____  _____\n"
               "  / / / __ \\/ __  / __ `/ / / /// ___/  /  |/ / __ \\/ __/ _ \\/ ___/\n"
               " / / / /_/ / /_/ / /_/ / /_/ / (__  )  / /|  / /_/ / /_/  __(__  ) \n"
               "/_/  \\____/\\__,_/\\__,_/\\__, / /____/  /_/ |_/\\____/\\__/\\___/____/  \n"
               "                      /____/                                       \n");
        printf("----------------------------------------------------------------\n");



        //商品过期提醒
        if((fp= fopen("..\\data\\products_data.txt","r"))==NULL){
            printf("读取文件失败\n");
            system("pause");
        }
        fread(&products_list, sizeof(products ),1,fp);
        while(!feof(fp)){
            //把商品生产日期给到date2
            date2.tm_year=products_list.data.year-1900;
            date2.tm_mon=products_list.data.month-1;
            date2.tm_mday=products_list.data.day;
            //计算商品生产日期的时间戳
            time_t b= mktime(&date2);
            //计算时间戳间的相差时间得到日期差
            diff= (int)difftime(a,b)/(60*60*24);
            if(diff>products_list.exp){
                printf("%s\t%s <<<当前商品已过期(过期%d天)，请及时清理！！！\n",
                       products_list.id,products_list.name,diff-products_list.exp);
                flag_1=1;
            }
            else if(diff>products_list.exp-7){
                printf("%s\t%s <<<当前商品快要过期了(剩余%d天)，请注意！！！\n",
                       products_list.id,products_list.name,7);
                flag_1=1;
            }
            else if(diff>products_list.exp-15){
                printf("%s\t%s <<<当前商品快要过期了(剩余%d天)，请注意！！！\n",
                       products_list.id,products_list.name,15);
                flag_1=1;
            }
            else if(diff>products_list.exp-30){
                printf("%s\t%s <<<当前商品快要过期了(剩余%d天)，请注意！！！\n",
                       products_list.id,products_list.name,30);
                flag_1=1;
            }

            fread(&products_list, sizeof(products ),1,fp);
        }
        fclose(fp);
        if(flag_1 != 1){
            printf("***暂无过期提醒信息!!!***\n");
        }
        else{
            printf("---------------------------------\n");
            printf("过期提醒输出完毕!!!\n");
        }
        system("pause");
        system("cls");
        break;
    }

}
//进度条
void proc(){
    int i = 0;
    int random_num_0,random_num_1;
    random_num_0=rand()%50+1;
    random_num_1=rand()%50+51;
    char buf[102];
    memset(buf, '\0', sizeof(buf));
    const char *lable = "|/-\\";
    while (i<=100){
        printf("[%-101s][%d%%][%c]\r", buf,i,lable[i%4]);
        fflush(stdout);
        buf[i]='=';
        Sleep(20);
        if(i==random_num_1||i==random_num_0){
            Sleep(500);
        }
        i++;
    }
    printf("\n");
}
//获取时间
void print_Currenttime(){
    //获取当前时间
    //可以用来自动记录入库时间和计算物品是否过期
    time_t Curtime = time(NULL);
    struct tm *ptm= localtime(&Curtime);
    printf("现在是%d年%d月%d日,%d:%d:%d\n",ptm->tm_year+1900,ptm->tm_mon+1,ptm->tm_mday,
           ptm->tm_hour,ptm->tm_min,ptm->tm_sec);

}
//登录系统
void login(){
    //登录系统用来分权
    int choice,i,k,j,flag;
    char input_id[10];
    char input_password[15];
    while(1){
        i=0;
        flag=0;
        system("cls");
        print_Currenttime();
        printf("    __                  _      \n"
               "   / /   ____   ____ _ (_)____ \n"
               "  / /   / __ \\ / __ `// // __ \\\n"
               " / /___/ /_/ // /_/ // // / / /\n"
               "/_____/\\____/ \\__, //_//_/ /_/ \n"
               "             /____/            \n");
        printf("-----------------------------------------\n");
        printf("请选择登录方式:\n1.员工\n2.管理员\n3.找回密码\n4.退出程序\n");
        printf(">>> ");
        scanf("%d",&choice);
        //读取员工文件
        FILE *fp;
        if((fp= fopen("..\\data\\emp_data.txt","r"))==0){
            printf("读取员工信息失败！");
            system("pause");
            continue;
        }
        //将员工文件中的信息写入缓存emp_temp[N];
        //后续操作(判断账号是否存在，判断是否为管理员)在缓存中进行
        fread(&emp_list,sizeof (emp),1,fp);
        while (!feof(fp)){
            emp_temp[i]=emp_list;
            i++;
            fread(&emp_list,sizeof (emp),1,fp);
        }
        fclose(fp);

        if(choice==1){
            printf("请输入您的编号:");
            scanf("%s",input_id);
            printf("请输入您的密码:");
            scanf("%s",input_password);

            //匹配输入的id和文件中存在的id

            for(k=0;k<i;k++){
                //如果存在则进行跳转
                if((strcmp(input_id,emp_temp[k].id)==0 && strcmp(input_password,emp_temp[k].password)==0 && emp_temp[k].chance<1)
                    ||(strcmp(input_id,emp_temp[k].id)==0 && emp_temp[k].chance<1)){
                    printf("账号已锁，请找回密码\n");
                    flag=1;
                    system("pause");
                    break;
                }

                else if(strcmp(input_id,emp_temp[k].id)==0 && strcmp(input_password,emp_temp[k].password)==0){
                    if(emp_temp[k].chance>=1){
                        printf("登陆成功！\n");
                        flag=1;
                        emp_temp[k].chance=3;
                        fp = fopen("..\\data\\emp_data.txt","w");
                        for(j=0;j<i;j++){
                            fwrite(&emp_temp[j], sizeof(emp),1,fp);
                        }
                        fclose(fp);
                        system("pause");
                        outbound_menu();
                    }

                }
                else if(strcmp(input_id,emp_temp[k].id)==0 && strcmp(input_password,emp_temp[k].password)!=0){
                    emp_temp[k].chance--;
                    fp = fopen("..\\data\\emp_data.txt","w");
                    for(j=0;j<i;j++){
                        fwrite(&emp_temp[j], sizeof(emp),1,fp);
                    }
                    fclose(fp);
                    flag=1;
                    printf("密码错误!剩余%d次机会!!!\n",emp_temp[k].chance);
                    system("pause");

                }
            }
            //不存在执行到下面输出信息
            if(flag==0){
                printf("账号错误，请检查后重试123!\n");
                system("pause");
                continue;
            }


        }
        else if(choice==2){
            printf("请输入您的编号:");
            scanf("%s",input_id);
            printf("请输入您的密码:");
            scanf("%s",input_password);
            //与第一个操作类似
            for(k=0;k<i;k++){
                if(strcmp(input_id,emp_temp[k].id)==0 && strcmp(input_password,emp_temp[k].password)==0){
                    if(emp_temp[k].admin==1){
                        printf("登陆成功！\n");
                        system("pause");
                        menu_admin_0();
                    }
                    else{
                        printf("您不是管理员!\n");
                        system("pause");
                        continue;
                    }

                }
            }

            printf("账号或密码错误，请检查后重试!\n");
            system("pause");
            continue;
        }
        else if(choice==3){
            findback();
        }
        else if(choice==4){
            exit(0);
        }
        else{
            printf("选择错误!");
            system("pause");
        }
    }

}
//找回密码
void findback(){
    FILE *fp;
    int flag;
    int i,j;
    char a[10];//账号
    char name[15];//姓名
    char password_1[11],password_2[11];
    char n[15];//电话号
    char color[15];//颜色
    char eat[20];//食物
    char place[50];//住址
    while(1){
        flag=0;
        i=0;
        getchar();
        printf("请输入您的账号：");
        gets(a);
        printf("请输入账号所有者的姓名：");
        gets(name);
        /*printf("请输入账号所有者的身份证号：");
        gets(num);*/
        printf("请输入账号所有者的电话：");
        gets(n);
        printf("请输入账号所有者喜爱的颜色：");
        gets(color);
        printf("请输入账号所有者的喜爱的食物：");
        gets(eat);
        printf("请输入账号所有者的住址：");
        gets(place);
        system("cls");
        //打开文件
        fp=fopen("..\\data\\emp_data.txt","r");
        if(fp==NULL)
        {
            printf("打开失败");
            system("pause");
            break;
        }
        //写入缓存
        else{
            fread(&emp_temp[i],sizeof(emp),1,fp);
            while(!feof(fp))
            {
                if(strcmp(emp_temp[i].id,a)==0)
                {
                    if(strcmp(emp_temp[i].name,name)==0)
                    {
                        flag++;
                    }
                    if(strcmp(emp_temp[i].phone,n)==0)
                    {
                        flag++;
                    }
                    if(strcmp(emp_temp[i].addr,place)==0)
                    {
                        flag++;
                    }
                    if(strcmp(emp_temp[i].food,eat)==0)
                    {
                        flag++;
                    }
                    if(strcmp(emp_temp[i].color,color)==0)
                    {
                        flag++;
                    }

                }

                i++;
                fread(&emp_temp[i],sizeof(emp),1,fp);
            }
            fclose(fp);


        }
        while(1){
            if(flag>=4){
                printf("请输入您新的密码：");
                scanf("%s",password_1);
                system("cls");
                printf("请再次输入您的新密码：");
                scanf("%s",password_2);
                if(strcmp(password_1,password_2)==0)
                {
                    fp=fopen("..\\data\\emp_data.txt","w");
                    if(fp==NULL)
                    {
                        printf("打开失败");
                        system("pause");
                        break;
                    }
                    else
                    {
                        for(j=0;j<i;j++)
                        {
                            if(strcmp(emp_temp[j].id,a)==0)
                            {
                                strcpy(emp_temp[j].password,password_2);
                                emp_temp[j].chance=3;
                                emp_temp[j].state=0;
                            }
                            fwrite(&emp_temp[j],sizeof(emp),1,fp);
                        }

                    }
                    printf("修改完成\n");
                }
                else
                {
                    printf("两次密码不一致,请重试\n");
                    continue;
                }
            }
            else{
                printf("找回密码失败！！！账号已彻底锁定，如需解锁请联系系统管理员!!!\n");
                for(j=0;j<i;j++)
                {
                    if(strcmp(emp_temp[j].id,a)==0)
                    {
                        emp_temp[j].state=1;
                    }
                    fwrite(&emp_temp[j],sizeof(emp),1,fp);
                }
            }
            fclose(fp);

            break;
        }
        system("pause");
        break;
    }

}

//销售
void outbound_menu(){
    //出货系统菜单
    int choice;
    while(1){
        system("cls");
        printf("   _____  __                                                  \n"
               "  / ___/ / /_   ____   ____     ____ ___   ___   ____   __  __\n"
               "  \\__ \\ / __ \\ / __ \\ / __ \\   / __ `__ \\ / _ \\ / __ \\ / / / /\n"
               " ___/ // / / // /_/ // /_/ /  / / / / / //  __// / / // /_/ / \n"
               "/____//_/ /_/ \\____// .___/  /_/ /_/ /_/ \\___//_/ /_/ \\__,_/  \n"
               "                   /_/                                        \n");
        printf("-----------------------------------------\n");
        jitang();
        printf("1.商品出库\n2.会员系统\n3.库存查询\n4.退出登录\n5.退出程序\n");
        printf(">>> ");
        scanf("%d",&choice);

        if(choice==1){
            outbound();
        }
        else if(choice==2){
            vip_point_menu();
        }
        else if(choice==3){
            system("cls");
            printf("1.全部输出\n2.指定查询\n");
            printf(">>> ");
            scanf("%d",&choice);
            //直接调用写好的商品输出函数
            if(choice==1){
                output_all_products();
            }
            else if(choice==2){
                serch_products();
            }
        }
        else if(choice==4){
            break;
        }
        else if(choice==5){
            exit(0);
        }
        else{
            printf("选择有误!\n");
            system("pause");
        }

    }

}
void outbound(){

    FILE *fp;

    char input_id[10],input_phone[12];
    int choice,i,k,j,flag,num,x;
    double price;
    while(1){
        i=0;
        flag=0;
        system("cls");
        printf("输入要出库的商品id(模拟扫码):");
        scanf("%s",input_id);


        if((fp=fopen("..\\data\\products_data.txt","r"))==NULL){
            printf("文件读取失败，请重试(05)\n");
            system("pause");
            break;
        }
        fread(&products_list,sizeof (products),1,fp);
        while (!feof(fp)){
            pro_temp[i]=products_list;
            i++;
            fread(&products_list,sizeof (products),1,fp);
        }
        fclose(fp);

        //打开出货单文件，并写入当前出货信息
        if((fp=fopen("..\\data\\list_data.txt","ab"))==NULL){
            printf("文件初始化失败，请重试(05)\n");
            system("pause");
            break;
        }

        for(k=0;k<i;k++){
            if(strcmp(input_id,pro_temp[k].id)==0){
                printf("-------------找到商品信息如下-------------\n");
                printf("编号\t    名称\t    进价\t     售价\t    产地\t     生产日期\t      保质期(day)\t  库存\t\n");
                printf("%s\t    %-10s\t    %-5.2f\t     %-5.2f\t    %-10s\t     %d-%d-%d\t      %-10d\t  %d\t",pro_temp[k].id,pro_temp[k].name,
                       pro_temp[k].price_in,pro_temp[k].price_out,pro_temp[k].addr,
                       pro_temp[k].data.year,pro_temp[k].data.month,pro_temp[k].data.day,
                       pro_temp[k].exp,pro_temp[k].num);
                printf("请输入出库数量:");
                scanf("%d",&num);
                strcpy(listTemp.name,pro_temp[k].name);
                listTemp.price=pro_temp[k].price_out;
                if(num<=pro_temp[k].num){
                    listTemp.num=num;
                    pro_temp[k].num-=num;   //缓存中库存更新
                }
                else
                {
                    printf("商品库存不足,该商品当前数量:%d 件\n",pro_temp[k].num);
                    printf("请重试\n");
                    flag=1;
                    continue;
                }
                flag=1;
                fwrite(&listTemp,sizeof (list_temp),1,fp);
            }
        }
        if(flag!=1){
            printf("未找到该商品信息,请手动输入金额\n");
            printf(">>> ");
            scanf("%lf",&price);

            printf("请输入数量\n");
            printf(">>> ");
            scanf("%d",&num);
            strcpy(listTemp.name,"未识别商品");
            listTemp.num=num;
            listTemp.price=price;
            fwrite(&listTemp,sizeof (list_temp),1,fp);
        }
        fclose(fp);

        //把库存更新写入文件
        fp= fopen("..\\data\\products_data.txt","w");
        for(k=0;k<i;k++){
            fwrite(&pro_temp[k],sizeof(products),1,fp);
        }
        fclose(fp);

        printf("继续吗? 1.Yes\\2.No\n");
        scanf("%d",&choice);
        if(choice==1){
            continue;
        }
        else{
            printf("出货单已生成\n");
            x = (int)print_outbound_list();
        }


        //积分自动记录
        printf("是否有会员账户\n");
        printf("1.有\n");
        printf("2.无\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("请输入会员账户；");
            scanf("%s",input_phone);
            fp=fopen("..\\data\\vip_data.txt","r");
            if(fp==NULL)
            {
                printf("打开失败");
                system("pause");
                break;
            }
            i=0;
            fread(&vip_list, sizeof(vip), 1, fp);
            while (!feof(fp)) {
                vip_temp[i]=vip_list;
                if (strcmp(vip_temp[i].id, input_phone) == 0) {
                    vip_temp[i].point += x;
                    printf("本次获得%d点积分,共%d点积分!\n",x,vip_temp[i].point+x);
                }
                i++;
                fread(&vip_list, sizeof(vip), 1, fp);

            }
            fclose(fp);

            fp=fopen("..\\data\\vip_data.txt","w");
            if(fp==NULL)
            {
                printf("打开失败");
            }
            else
            {
                for(j=0;j<i;j++)
                {
                    fwrite(&vip_temp[j],sizeof(vip),1,fp);
                }
            }
            fclose(fp);

        }
        break;

    }
    system("pause");
}
double print_outbound_list(){
    double sum_price=0;
    FILE *fp;
    while(1){
        if((fp = fopen("..\\data\\list_data.txt","r"))==NULL){
            printf("读取销售信息失败!请重试!\n");
            system("pause");
            break;
        }
        printf("-------------全部信息如下-------------\n");
        printf("名称\t\t单价\t数量\t总价\t\n");
        fread(&listTemp,sizeof (list_temp),1,fp);
        while(!feof(fp)){

            printf("%-15s\t%.2f\t%d\t%.2f\t\n",listTemp.name,listTemp.price,listTemp.num,listTemp.num*listTemp.price);
            sum_price+=listTemp.price*listTemp.num;
            fread(&listTemp,sizeof (list_temp),1,fp);
        }
        fclose(fp);

        if((fp=fopen("..\\data\\list_data.txt","w"))==NULL){
            printf("文件初始化失败，请重试(05)\n");
            system("pause");
            break;
        }
        fclose(fp);

        printf("--------------------------\n总计:%.2f 元\n",sum_price);

        printf("打印结束\n");
        system("pause");
        break;
    }
    return sum_price*100;

}

//商品
void menu_admin_0(){
    int choice;
    while (1){
        system("cls");
        printf("    ___        __            _                                        \n"
               "   /   |  ____/ /____ ___   (_)____     ____ ___   ___   ____   __  __\n"
               "  / /| | / __  // __ `__ \\ / // __ \\   / __ `__ \\ / _ \\ / __ \\ / / / /\n"
               " / ___ |/ /_/ // / / / / // // / / /  / / / / / //  __// / / // /_/ / \n"
               "/_/  |_|\\__,_//_/ /_/ /_//_//_/ /_/  /_/ /_/ /_/ \\___//_/ /_/ \\__,_/  \n"
               "                                                                      \n");
        printf("-----------------------------------------\n");
        printf("\t欢迎使用超市商品管理系统V1.2\n");
        printf("\t   1.进入商品信息管理\n");
        printf("\t   2.进入员工信息管理\n");
        printf("\t   3.退出登录\n");
        printf("\t   4.退出程序\n");
        printf("-----------------------------------------\n");
        printf("请选择:");
        scanf("%d",&choice);
        if(choice==1){
            menu_admin_1();
        }
        else if(choice==2){
            menu_admin_2();
        }
        else if(choice==3){
            login();
        }
        else if(choice==4){
            exit(0);
        }
        else{
            printf("选择有误！请检查后重新输入!\n");
        }
    }

}
void menu_admin_1(){

    int choice;
    while (1){
        system("cls");
        printf("   ______                   __                                      \n"
               "  / ____/____   ____   ____/ /_____   ____ ___   ___   ____   __  __\n"
               " / / __ / __ \\ / __ \\ / __  // ___/  / __ `__ \\ / _ \\ / __ \\ / / / /\n"
               "/ /_/ // /_/ // /_/ // /_/ /(__  )  / / / / / //  __// / / // /_/ / \n"
               "\\____/ \\____/ \\____/ \\__,_//____/  /_/ /_/ /_/ \\___//_/ /_/ \\__,_/  \n"
               "                                                                    \n");
        printf("-----------------------------------------\n");
        printf("\t欢迎使用超市商品管理系统V1.2\n");
        printf("-----------------------------------------\n");
        printf("\t   1.录入商品信息\n");
        printf("\t   2.查看商品总览\n");
        printf("\t   3.查找特定商品\n");
        printf("\t   4.修改特定商品\n");
        printf("\t   5.删除特定商品\n");
        printf("\t   6.返回主选单\n");
        printf("\t   7.查看今日提醒\n");
        printf("\t   8.退出程序\n");
        printf("-----------------------------------------\n");
        printf("请选择:");
        scanf("%d",&choice);
        if(choice==1){
            system("cls");
            add_products();

        }
        else if(choice==2){
            system("cls");

            output_all_products();
        }
        else if(choice==3){
            system("cls");

            serch_products();
        }
        else if(choice==4){
            system("cls");

            edit_products();
        }
        else if(choice==5){
            system("cls");

            del_products();
        }
        else if(choice==6){
            menu_admin_0();
        }
        else if(choice==7){
            reminder();
        }
        else if(choice==8){
            exit(0);
        }
        else{
            printf("选择有误!请检查后重新输入!\n");
            system("pause");
            menu_admin_1();
        }
    }

}
void menu_admin_2(){

    int choice;
    while (1){
        system("cls");
        printf("                           __                                                          \n"
               "  ___   ____ ___   ____   / /____   __  __ ___   ___     ____ ___   ___   ____   __  __\n"
               " / _ \\ / __ `__ \\ / __ \\ / // __ \\ / / / // _ \\ / _ \\   / __ `__ \\ / _ \\ / __ \\ / / / /\n"
               "/  __// / / / / // /_/ // // /_/ // /_/ //  __//  __/  / / / / / //  __// / / // /_/ / \n"
               "\\___//_/ /_/ /_// .___//_/ \\____/ \\__, / \\___/ \\___/  /_/ /_/ /_/ \\___//_/ /_/ \\__,_/  \n"
               "               /_/               /____/                                                \n");
        printf("-----------------------------------------\n");
        printf("\t欢迎使用超市商品管理系统V1.2\n");
        printf("-----------------------------------------\n");
        printf("\t   1.录入员工信息\n");
        printf("\t   2.查看员工总览\n");
        printf("\t   3.查找特定员工\n");
        printf("\t   4.修改员工信息\n");
        printf("\t   5.删除员工信息\n");
        printf("\t   6.返回主选单\n");
        printf("\t   7.退出程序\n");
        printf("-----------------------------------------\n");
        printf("请选择:");
        scanf("%d",&choice);
        if(choice==1){
            system("cls");
            add_emp();

        }
        else if(choice==2){
            system("cls");

            output_all_emp();
        }
        else if(choice==3){
            system("cls");

            serch_emp();
        }
        else if(choice==4){
            system("cls");

            edit_emp();
        }
        else if(choice==5){
            system("cls");

            del_emp();
        }
        else if(choice==6){
            menu_admin_0();
        }
        else if(choice==7){
            exit(0);
        }
        else{
            printf("选择有误!请检查后重新输入!\n");
            system("pause");
            menu_admin_2();
        }
    }

}
void add_products(){
    int choice;

    while(1){
        printf("请输入商品编码:\n");
        scanf("%s", products_list.id);
        printf("请输入商品名称:\n");
        scanf("%s", products_list.name);
        printf("请输入商品进价:\n");
        scanf("%lf", &products_list.price_in);
        printf("请输入商品售价:\n");
        scanf("%lf", &products_list.price_out);
        printf("请输入商品产地:\n");
        scanf("%s", products_list.addr);
        printf("请输入商品生产日期(格式:20xx-xx-xx):\n");
        scanf("%d-%d-%d", &products_list.data.year,&products_list.data.month,&products_list.data.day);
        printf("请输入保质期(day):\n");
        scanf("%d",&products_list.exp);
        printf("请输入商品数量:\n");
        scanf("%d", &products_list.num);


        printf("尝试保存信息中......\n");
        FILE *fp;
        if((fp=fopen("..\\data\\products_data.txt","ab"))==NULL){
            printf("文件打开失败，请重试(01)!\n");
            system("pause");
            return;
        }
        fwrite(&products_list,sizeof (products),1,fp);
        fclose(fp);
        printf("保存成功!\n");
        printf("录入结束,是否继续录入?\n1.Yes\\2.No\n");
        scanf("%d",&choice);
        if(choice==1){
            continue;
        }
        else menu_admin_1();
    }

}
void del_products(){
    int choice,i=0,k,flag=0;
    char input_id[10];
    FILE *fp;
    if((fp=fopen("..\\data\\products_data.txt","r"))==NULL){
        printf("文件读取失败，请重试(02)\n");
        system("pause");
        menu_admin_1();
    }
    fread(&products_list,sizeof (products),1,fp);
    while(!feof(fp)){
        pro_temp[i]=products_list;
        i++;
        fread(&products_list,sizeof (products),1,fp);
    }
    fclose(fp);

    if((fp=fopen("..\\data\\products_data.txt","w"))==NULL){
        printf("文件读取失败，请重试(03)\n");
        system("pause");
        menu_admin_1();
    }

    printf("请输入要删除的物品的编号:");
    scanf("%s",input_id);

    for(k=0;k<i;k++){
        if(strcmp(input_id, pro_temp[k].id) == 0){
            printf("确认删除吗？1.Yes\\2.No\n");
            scanf("%d",&choice);
            if(choice==1){
                flag=1;
                printf("删除成功!\n");
                system("pause");
                continue;
            }
            else{
                flag=2;
                fwrite(&pro_temp[k], sizeof (products), 1, fp);
            }
        }
        else{
            fwrite(&pro_temp[k], sizeof (products), 1, fp);
        }
    }
    if(flag==0){
        printf("未找到商品!\n");
        system("pause");
    }
    else if(flag==2){
        printf("取消删除!\n");
        system("pause");
    }
    fclose(fp);
    menu_admin_1();
}
void output_all_products(){
    int choice;
    FILE *fp;
    if((fp=fopen("..\\data\\products_data.txt","r"))==NULL){
        printf("文件读取失败，请重试(04)\n");
        system("pause");
        return;
    }

    printf("----------------------------------------------------全部信息如下-------------------------------------"
           "-----------------\n");
    printf("编号\t    名称\t    进价\t     售价\t    产地\t     生产日期\t      保质期(day)\t  库存\t\n");
    fread(&products_list,sizeof (products),1,fp);
    while(!feof(fp)){

        printf("%s\t    %-10s\t    %-5.2f\t     %-5.2f\t    %-10s\t     %d-%d-%d\t      %-10d\t  %d\t\n",
               products_list.id,products_list.name,products_list.price_in,products_list.price_out,
               products_list.addr,products_list.data.year,products_list.data.month,products_list.data.day,
               products_list.exp,products_list.num);
        fread(&products_list,sizeof (products),1,fp);

    }
    fclose(fp);
    printf("查询完成,返回菜单\n");
    system("pause");
    //menu_admin_1();

}
void serch_products(){
    int choice,flag;
    char input_id[10];
    char input_name[20];
    char *p1,*p2;
    FILE *fp;
    while(1){
        flag=0;
        if((fp=fopen("..\\data\\products_data.txt","r"))==NULL){
            printf("文件读取失败，请重试(05)\n");
            system("pause");
            break;
        }
        system("cls");
        printf("请输入查找方式:\n");
        printf("1.编号\n2.名称(模糊)\n");
        scanf("%d",&choice);
        if(choice==1){
            printf("请输入查找的商品编号:");
            scanf("%s",input_id);
            fread(&products_list,sizeof (products),1,fp);
            while (!feof(fp)){
                if(strcmp(input_id,products_list.id)==0){
                    printf("查找成功!\n");
                    printf("-------------商品信息如下-------------\n");
                    printf("编号\t    名称\t    进价\t     售价\t    产地\t     生产日期\t      保质期(day)\t  库存\t\n");
                    printf("%s\t    %-10s\t    %-5.2f\t     %-5.2f\t    %-10s\t     %d-%d-%d\t      %-10d\t  %d\t\n",products_list.id,
                           products_list.name,products_list.price_in,products_list.price_out,
                           products_list.addr,products_list.data.year,products_list.data.month,
                           products_list.data.day,products_list.exp,products_list.num);
                    flag=1;
                }
                fread(&products_list,sizeof (products),1,fp);
            }
            if(flag!=1){
                printf("未找到该商品!请检查后继续查询!\n");
                system("pause");
            }
        }

        else if(choice==2){
            printf("请输入名称:\n");
            scanf("%s",input_name);
            printf("编号\t    名称\t    进价\t     售价\t    产地\t     生产日期\t      保质期(day)\t  库存\t\n");
            fread(&products_list, sizeof(products ),1,fp);
            while(!feof(fp)){
                if(strstr(products_list.name,input_name)!=NULL){
                    printf("%s\t    %-10s\t    %-5.2f\t     %-5.2f\t    %-10s\t     %d-%d-%d\t      %-10d\t  %d\t\n",products_list.id,
                           products_list.name,products_list.price_in,products_list.price_out,
                           products_list.addr,products_list.data.year,products_list.data.month,
                           products_list.data.day,products_list.exp,products_list.num);
                    flag=1;
                }

                fread(&products_list, sizeof(products ),1,fp);
            }
            if(flag==0){
                printf("未找到信息!");
            }
        }


        else{
            printf("输入错误!\n");
            continue;
        }

        fclose(fp);
        printf("要继续查询吗?1.Yes\\2.NO\n");
        scanf("%d",&choice);
        if(choice==1){
            continue;
        }
        else{
            break;
        }
    }

}
void edit_products(){
    FILE *fp;
    int i=0,flag=0,k,new_num,choice;
    double new_price;
    char input_id[10],new_name[20],new_addr[50];
    DATA new_data;
    if((fp=fopen("..\\data\\products_data.txt","r"))==NULL){
        printf("文件打开失败，请重试(06)!\n");
        system("pause");
        return;
    }
    printf("请输入要修改的商品的编号\n");
    scanf("%s",input_id);
    fread(&products_list,sizeof (products),1,fp);
    while (!feof(fp)){
        if(strcmp(input_id,products_list.id)==0){
            printf("查找成功!\n");
            printf("-------------商品信息如下-------------\n");
            printf("商品编号\t名称\t进价\t售价\t产地\t生产日期\t保质期(day)\t库存\t\n");
            printf("%s\t\t%s\t%.2f\t%.2f\t%s\t%d-%d-%d\t%d\t%d\t\n",products_list.id,products_list.name,products_list.price_in,
                   products_list.price_out,products_list.addr,products_list.data.year,products_list.data.month,products_list.data.day,products_list.exp,products_list.num);
            flag=1;
        }
        fread(&products_list,sizeof (products),1,fp);
    }
    if(flag!=1){
        printf("未找到该商品!请检查后继续操作!\n");
        system("pause");
        fclose(fp);
        edit_products();
    }
    fclose(fp);


    if((fp=fopen("..\\data\\products_data.txt","r"))==NULL){
        printf("文件打开失败，请重试(07)!\n");
        system("pause");
        return;
    }
    fread(&products_list,sizeof (products),1,fp);
    while(!feof(fp)){
        pro_temp[i]=products_list;
        i++;
        fread(&products_list,sizeof (products),1,fp);
    }
    fclose(fp);


    if((fp=fopen("..\\data\\products_data.txt","w"))==NULL){
        printf("文件打开失败，请重试(08)!\n");
        system("pause");
        return;
    }

    for(k=0;k<i;k++){
        if(strcmp(input_id, pro_temp[k].id) == 0){
            printf("你想要修改?\n1.名称\n2.进价\n3.售价\n4.产地\n5.生产日期\n6.保质期\n7.数量\n");
            scanf("%d",&choice);
            if(choice==1){
                printf("请输入新名称:\n");
                scanf("%s",new_name);
                strcpy(pro_temp[k].name, new_name);
                printf("修改成功\n");
            }
            else if(choice==2){
                printf("请输入新进价:\n");
                scanf("%lf",&new_price);
                pro_temp[k].price_in=new_price;
                printf("修改成功\n");
            }
            else if(choice==3){
                printf("请输入新售价:\n");
                scanf("%lf",&new_price);
                pro_temp[k].price_out=new_price;
                printf("修改成功\n");
            }
            else if(choice==4){
                printf("请输入新产地:\n");
                scanf("%s",new_addr);
                strcpy(pro_temp[k].addr,new_addr);
                printf("修改成功\n");
            }
            else if(choice==5){
                printf("请输入新生产日期(20xx-x-x):\n");
                scanf("%d-%d-%d", &new_data.year,&new_data.month,&new_data.day);
                pro_temp[k].data=new_data;
                printf("修改成功\n");
            }
            else if(choice==6){
                printf("请输入新保质期:\n");
                scanf("%d",&new_num);
                pro_temp[k].exp=new_num;
                printf("修改成功\n");
            }
            else if(choice==7){
                printf("请输入新数量:\n");
                scanf("%d",&new_num);
                pro_temp[k].num=new_num;
                printf("修改成功\n");
            }
            else{
                printf("输入错误!请检查后重试!\n");
            }

        }
        //读一个写一个，有修改的先被修改后再写进去
        fwrite(&pro_temp[k], sizeof (products), 1, fp);

    }
    fclose(fp);
    printf("操作已保存\n");
}

//员工
void add_emp(){

    int choice;
    while(1){
        //获取当前时间
        time_t Curtime = time(NULL);
        struct tm *ptm= localtime(&Curtime);
        printf("请输入员工编码:\n");
        scanf("%s", emp_list.id);
        printf("请输入员工姓名:\n");
        scanf("%s", emp_list.name);
        printf("请输入员工性别:\n");
        scanf("%s", emp_list.gender);
        /*
        printf("请输入员工入职日期(20xx-x-x):\n");
        scanf("%d-%d-%d", &emp_list.data.year,&emp_list.data.month,&emp_list.data.day);
        */
        emp_list.data.year=ptm->tm_year+1900;
        emp_list.data.month=ptm->tm_mon+1;
        emp_list.data.day=ptm->tm_mday;

        printf("请为员工初始化系统密码(<10位数):\n");
        scanf("%s", emp_list.password);
        printf("是否要将该用户设为管理员？1.Yes\\2.NO\n");
        scanf("%d",&choice);
        if(choice==1){
            emp_list.admin=1;
        }
        else{
            emp_list.admin=0;
        }
        //录入找回密码所需要的信息
        printf("下面设置密保问题\n");
        printf("请输入您的手机号码\n>>> ");
        scanf("%s",emp_list.phone);
        printf("请输入您喜欢的颜色\n>>> ");
        scanf("%s",emp_list.color);
        printf("请输入您喜欢的食物\n>>> ");
        scanf("%s",emp_list.food);
        printf("请输入您的家庭住址\n>>> ");
        scanf("%s",emp_list.addr);
        emp_list.chance=3;//密码错误次数
        emp_list.state=0;//账号是否被锁，默认0未锁
        printf("尝试保存信息中......\n");
        FILE *fp;
        if((fp=fopen("..\\data\\emp_data.txt","ab"))==NULL){
            printf("文件打开失败，请重试(01)!\n");
            system("pause");
            return;
        }
        fwrite(&emp_list,sizeof (emp),1,fp);
        fclose(fp);
        printf("保存成功!\n");
        printf("录入结束,是否继续录入?\n1.Yes\\2.No\n");
        scanf("%d",&choice);
        if(choice==1){
            continue;
        }
        else menu_admin_2();
        }


}
void del_emp() {
    int choice,i=0,k,flag=0;
    char input_id[10];
    FILE *fp;
    if((fp=fopen("..\\data\\emp_data.txt","r"))==NULL){
        printf("文件读取失败，请重试(02)\n");
        system("pause");
        menu_admin_1();
    }
    fread(&emp_list,sizeof (emp),1,fp);
    while(!feof(fp)){
        emp_temp[i]=emp_list;
        i++;
        fread(&emp_list,sizeof (emp),1,fp);
    }
    fclose(fp);

    if((fp=fopen("..\\data\\emp_data.txt","w"))==NULL){
        printf("文件读取失败，请重试(03)\n");
        system("pause");
        menu_admin_2();
    }

    printf("请输入要删除的员工的编号:");
    scanf("%s",input_id);

    for(k=0;k<i;k++){
        if(strcmp(input_id, emp_temp[k].id) == 0){
            printf("确认删除吗？1.Yes\\2.No\n");
            scanf("%d",&choice);
            if(choice==1){
                flag=1;
                printf("删除成功!\n");
                system("pause");
                continue;
            }
            else{
                flag=2;
                fwrite(&emp_temp[k], sizeof (emp), 1, fp);
            }
        }
        else{
            fwrite(&emp_temp[k], sizeof (emp), 1, fp);
        }
    }
    if(flag==0){
        printf("未找到该员工!\n");
        system("pause");
    }
    else if(flag==2){
        printf("取消删除!\n");
        system("pause");
    }
    fclose(fp);
    menu_admin_2();
}
void output_all_emp(){
    int choice;
    FILE *fp;
    if((fp=fopen("..\\data\\emp_data.txt","r"))==NULL){
        printf("文件读取失败，请重试(04)\n");
        system("pause");
        return;
    }

    printf("-------------全部信息如下-------------\n");
    printf("员工编号\t姓名\t性别\t入职日期\t管理员\t\n");

    fread(&emp_list,sizeof (emp),1,fp);
    while(!feof(fp)){

        printf("%s\t\t%s\t%s\t%d-%d-%d\t",emp_list.id,emp_list.name,emp_list.gender,
               emp_list.data.year,emp_list.data.month,emp_list.data.day);
        if(emp_list.admin==1){

            printf("是\t\n");

        }
        else{

            printf("否\t\n");

        }

        fread(&emp_list,sizeof (emp),1,fp);

    }
    fclose(fp);
    printf("查询完成,返回菜单\n");
    system("pause");
    menu_admin_2();

}
void serch_emp(){
    int choice,flag=0;
    char input_id[10];
    char input_name[20];
    char *p1,*p2;
    FILE *fp;
    if((fp=fopen("..\\data\\emp_data.txt","r"))==NULL){
        printf("文件读取失败，请重试(05)\n");
        system("pause");
        return;
    }
    system("cls");
    printf("请输入查找方式:\n");
    printf("1.编号\n2.姓名(模糊)\n");
    scanf("%d",&choice);
    if(choice==1){
        printf("请输入查找的员工编号:");
        scanf("%s",input_id);
        fread(&emp_list,sizeof (emp),1,fp);
        while (!feof(fp)){
            if(strcmp(input_id,emp_list.id)==0){
                printf("查找成功!\n");
                printf("-------------员工信息如下-------------\n");
                printf("员工编号\t姓名\t性别\t入职日期\t\n");
                printf("%s\t\t%s\t%s\t%d-%d-%d\n",emp_list.id,emp_list.name,emp_list.gender,
                       emp_list.data.year,emp_list.data.month,emp_list.data.day);
                flag=1;
            }
            fread(&emp_list,sizeof (emp),1,fp);
        }
        if(flag!=1){
            printf("未找到该员工!请检查后继续查询!\n");
            system("pause");
        }
    }
    else if(choice==2){
        printf("请输入信息:\n");
        scanf("%s",input_name);
        printf("员工编号\t姓名\t性别\t入职日期\t\n");
        fread(&emp_list,sizeof (emp),1,fp);
        while (!feof(fp)){
            if(strstr(emp_list.name,input_name)!=NULL){

            printf("%s\t\t%s\t%s\t%d-%d-%d\n",emp_list.id,emp_list.name,emp_list.gender,
                   emp_list.data.year,emp_list.data.month,emp_list.data.day);
            flag=1;
            }
            fread(&emp_list,sizeof(emp),1,fp);
        }
        if(flag==0){
            printf("未找到任何信息!\n");
        }
    }
    else{
        printf("输入错误!\n");
        serch_emp();
    }

    fclose(fp);
    printf("要继续查询吗?1.Yes\\2.NO\n");
    scanf("%d",&choice);
    if(choice==1){
        serch_emp();
    }
    else{
        menu_admin_2();
    }
}
void edit_emp(){
    FILE *fp;
    int i=0,flag=0,k,choice;
    char input_id[10],new_name[15],new_gender[5],new_password[11];
    int new_admin;
    DATA new_data;
    if((fp=fopen("..\\data\\emp_data.txt","r"))==NULL){
        printf("文件打开失败，请重试(06)!\n");
        system("pause");
        return;
    }
    printf("请输入要修改的员工的编号\n");
    scanf("%s",input_id);
    fread(&emp_list,sizeof (emp),1,fp);
    while (!feof(fp)){
        if(strcmp(input_id,emp_list.id)==0){
            printf("查找成功!\n");
            printf("-------------员工信息如下-------------\n");
            printf("员工编号\t姓名\t性别\t入职日期\t管理员\t\n");
            printf("%s\t\t%s\t%s\t%d-%d-%d\t",emp_list.id,emp_list.name,emp_list.gender,
                   emp_list.data.year,emp_list.data.month,emp_list.data.day);
            if(emp_list.admin==1){

                printf("是\t\n");

            }
            else{

                printf("否\t\n");

            }
            flag=1;
        }
        fread(&emp_list,sizeof (emp),1,fp);
    }
    fclose(fp);
    if(flag!=1){
        printf("未找到该员工!请检查后继续操作!\n");
        system("pause");
        menu_admin_2();

    }


    if((fp=fopen("..\\data\\emp_data.txt","r"))==NULL){
        printf("文件打开失败，请重试(07)!\n");
        system("pause");
        return;
    }

    fread(&emp_list,sizeof (emp),1,fp);
    while(!feof(fp)){
        emp_temp[i]=emp_list;
        i++;
        fread(&emp_list,sizeof (emp),1,fp);
    }
    fclose(fp);


    if((fp=fopen("..\\data\\emp_data.txt","w"))==NULL){
        printf("文件打开失败，请重试(08)!\n");
        system("pause");
        return;
    }
    for(k=0;k<i;k++){
        if(strcmp(input_id, emp_temp[k].id) == 0){
            printf("你想要修改?\n1.姓名\n2.性别\n3.入职日期\n4.登录密码\n5.切换管理员状态\n");
            scanf("%d",&choice);
            if(choice==1){
                scanf("%s",new_name);
                strcpy(emp_temp[k].name, new_name);
                printf("修改成功\n");
            }
            else if(choice==2){
                scanf("%s",new_gender);
                strcpy(emp_temp[k].gender, new_gender);
                printf("修改成功\n");
            }

            else if(choice==3){
                scanf("%d-%d-%d", &new_data.year,&new_data.month,&new_data.day);
                emp_temp[k].data=new_data;
                printf("修改成功\n");

            }
            else if(choice==4){
                scanf("%s", new_password);
                strcpy(emp_temp[k].password, new_password);
                printf("修改成功\n");

            }
            else if(choice==5){
                printf("1.设定管理员\n2.取消管理员\n");
                printf("请选择>>>");
                scanf("%d",&choice);
                if(choice==1){
                    emp_temp[k].admin=1;
                    printf("修改成功\n");

                }
                else if(choice==2){
                    emp_temp[k].admin=0;
                    printf("修改成功\n");

                }
                else{
                    printf("选择有误!\n");
                }
            }

            else{
                printf("输入错误!请检查后重试!\n");
            }

        }
        //读一个写一个，有修改的先被修改后再写进去
        fwrite(&emp_temp[k], sizeof (emp), 1, fp);

    }
    fclose(fp);
}

//会员积分
void vip_point_menu(){
    int choice;
    while(1){
        system("cls");
        printf(" _    __ ____ ____                                  \n"
               "| |  / //  _// __ \\   ____ ___   ___   ____   __  __\n"
               "| | / / / / / /_/ /  / __ `__ \\ / _ \\ / __ \\ / / / /\n"
               "| |/ /_/ / / ____/  / / / / / //  __// / / // /_/ / \n"
               "|___//___//_/      /_/ /_/ /_/ \\___//_/ /_/ \\__,_/  \n"
               "                                                    \n");
        printf("-----------------------------------------\n");
        printf("1.注册会员账号\n2.查询会员积分\n3.查看所有会员账号\n4.修改账号信息\n5.核销会员积分\n6.退出\n");
        scanf("%d",&choice);
        if(choice==1){
            vip_reg();
        }
        else if(choice==2){
            point_check();
        }
        else if(choice==3){
            output_all_vip();
        }
        else if(choice==4){
            edit_vip();
        }
        else if(choice==5){
            point_use();
        }
        else if(choice==6){
            break;
        }

    }

}
void vip_reg(){
    char input_number[12];
    char input_password[11];
    FILE *fp;
    while (1){
        if((fp= fopen("..\\data\\vip_data.txt","ab"))==NULL){
            printf("初始化文件失败!\n");
            break;
        }
        printf("请输入您的电话号码:\n");
        scanf("%s",input_number);
        printf("请输入一个密码:\n");
        scanf("%s",input_password);
        strcpy(vip_list.id,input_number);
        strcpy(vip_list.password,input_password);
        vip_list.point=0;
        fwrite(&vip_list, sizeof(vip ),1,fp);
        fclose(fp);
        printf("创建成功!\n");
        system("pause");
        break;
    }

}
void output_all_vip(){
    FILE *fp;
    if((fp= fopen("..\\data\\vip_data.txt","r"))==NULL){
        printf("打开文件失败!\n");
        system("pause");
        return;
    }
    printf("账号\t\t积分\t密码\t\n");
    fread(&vip_list, sizeof(vip ),1,fp);
    while(!feof(fp)){
        printf("%-10s\t%-5d\t%-5s\n",vip_list.id,vip_list.point,vip_list.password);
        fread(&vip_list, sizeof(vip ),1,fp);
    }
    fclose(fp);
    system("pause");
}
void edit_vip(){
    FILE *fp;
    int k,i,choice,new_point;
    char input_id[12],new_password[11],new_id[12];
    while(1){
        i=0;
        if((fp= fopen("..\\data\\vip_data.txt","r"))==NULL){
            printf("打开文件失败!\n");
            system("pause");
            break;
        }
        fread(&vip_list,sizeof(vip),1,fp);
        while(!feof(fp)){
            vip_temp[i]=vip_list;
            i++;
            fread(&vip_list,sizeof(vip),1,fp);
        }
        fclose(fp);

        fp= fopen("..\\data\\vip_data.txt","w");

        printf("请输入要修改的账号:");
        scanf("%s",input_id);
        for(k=0;k<i;k++){
            if(strcmp(input_id,vip_temp[k].id)==0){
                printf("1.账号\n2.密码\n3.积分\n");
                scanf("%d",&choice);
                if(choice==1){
                    printf("请输入新的账号:");
                    scanf("%s",new_id);
                    strcpy(vip_temp[k].id,new_id);
                    printf("修改成功");
                }
                else if(choice==2){
                    printf("请输入新的密码:");
                    scanf("%s",new_password);
                    strcpy(vip_temp[k].password,new_password);
                    printf("修改成功");

                }
                else if(choice==3){
                    printf("请输入新的积分:");
                    scanf("%d",&new_point);
                    vip_temp[k].point=new_point;
                    printf("修改成功");

                }
            }
            fwrite(&vip_temp[k], sizeof(vip),1,fp);
        }
        fclose(fp);
        system("pause");
        break;
    }

}
void point_check(){
    char input_number[12];
    int flag;
    FILE *fp;
    while(1){
        flag=0;
        if((fp= fopen("..\\data\\vip_data.txt","r"))==NULL){
            printf("初始化文件失败!\n");
            break;
        }

        printf("请输入账号:\n");
        scanf("%s",input_number);
        fread(&vip_list,sizeof(vip),1,fp);
        while(!feof(fp)){
            if(strcmp(input_number,vip_list.id)==0){
                printf("共有%d点积分\n",vip_list.point);
                flag=1;
            }
            fread(&vip_list,sizeof(vip),1,fp);
        }
        fclose(fp);
        if(flag!=1){
            printf("未找到该账号\n");
        }
        system("pause");
        break;
    }


}
void point_use(){
    FILE *fp;
    char input_number[12],input_password[11];
    int flag,input_point,new_point,i,k;
    while(1){
        flag=0;
        i=0;
        if((fp= fopen("..\\data\\vip_data.txt","r"))==NULL){
            printf("读取文件失败!\n");
            break;
        }
        printf("请输入核销账号:");
        scanf("%s",input_number);
        /*fread(&vip_list, sizeof(vip ),1,fp);
        while(!feof(fp)){
            if(strcmp(input_number,vip_list.id)==0){
                printf("共有%d点积分\n",vip_list.point);
                if(input_point<=vip_list.point){
                    printf("请输入密码:");
                    scanf("%s",input_password);
                    if(strcmp(input_password,vip_list.password)==0){
                        new_point=vip_list.point-input_point;
                        printf("扣除完成,剩余%d个积分\n",new_point);
                    }
                    else{
                        printf("密码错误!请检查后重试");
                    }
                }
                else{
                    printf("积分数量不足!\n");
                }
                flag=1;
            }
            fread(&vip_list,sizeof(vip),1,fp);
        }*/

        fread(&vip_list, sizeof(vip ),1,fp);
        while(!feof(fp)){
            vip_temp[i]=vip_list;
            i++;
            fread(&vip_list, sizeof(vip ),1,fp);
        }
        fclose(fp);

        if((fp= fopen("..\\data\\vip_data.txt","w"))==NULL){
            printf("打开文件失败!\n");
            break;
        }

        for(k=0;k<i;k++){
            if(strcmp(input_number,vip_temp[k].id)==0){
                printf("共有%d点积分\n",vip_temp[k].point);
                printf("请输入核销积分:");
                scanf("%d",&input_point);
                printf("请输入密码:");
                scanf("%s",input_password);
                if(input_point<=vip_temp[k].point){

                    if(strcmp(input_password,vip_temp[k].password)==0){
                        new_point=vip_temp[k].point-input_point;
                        printf("扣除完成,剩余%d个积分\n",new_point);
                        vip_temp[k].point=new_point;
                    }
                    else{
                        printf("密码错误!请检查后重试");
                    }
                }
                else{
                    printf("积分不足!!!\n");
                }
                flag=1;
            }
            fwrite(&vip_temp[k], sizeof(vip ),1,fp);
        }
        fclose(fp);
        if(flag!=1){
            printf("未找到该账号!\n");
        }
        system("pause");
        break;
    }

}

int main(){
    int choice;
    time_t Curtime = time(NULL);
    struct tm *ptm= localtime(&Curtime);
    //检查是否是第一次使用程序，默认创建一个管理员账号
    FILE *fp;
    if((fp=fopen("..\\data\\emp_data.txt","r"))==NULL){
        fclose(fp);
        printf("检查到您是初次使用，下面将引导您创建一个管理员账户\n账号默认id:10001\n");
        //printf("请输入员工编码:\n");
        //scanf("%s", emp_list.id);
        strcpy(emp_list.id,"10001");
        //printf("请输入管理员账号:\n");
        //scanf("%s", emp_list.name);
        strcpy(emp_list.name,"Admin");
        //printf("请输入员工性别:\n");
        //scanf("%s", emp_list.gender);
        //strcpy(emp_list.gender,"");
        //printf("请输入员工入职日期(20xx-x-x):\n");
        //scanf("%d-%d-%d", &emp_list.data.year,&emp_list.data.month,&emp_list.data.day);
        emp_list.chance=3;
        emp_list.data.year=ptm->tm_year+1900;
        emp_list.data.month=ptm->tm_mon+1;
        emp_list.data.day=ptm->tm_mday;
        strcpy(emp_list.gender,"NULL");
        printf("请为初始化管理员密码(<10位数):\n");
        scanf("%s", emp_list.password);
        emp_list.admin=1;
        emp_list.state=0;
        printf("尝试保存信息中......\n");
        if((fp=fopen("..\\data\\emp_data.txt","ab"))==NULL){
            printf("文件保存失败，请重试(01)!\n");
            system("pause");
        }
        fwrite(&emp_list,sizeof (emp),1,fp);
        fclose(fp);
        printf("保存成功!\n");
        printf("!!!该管理员账号无法进行密码找回，请妥善保管密码信息!!!\n");
        system("pause");
    }
    printf("   __  __          __                  _____ __                   _____            __               \n"
           "  / / / /_______  / /__  __________   / ___// /_  ____  ____     / ___/__  _______/ /____  ____ ___ \n"
           " / / / / ___/ _ \\/ / _ \\/ ___/ ___/   \\__ \\/ __ \\/ __ \\/ __ \\    \\__ \\/ / / / ___/ __/ _ \\/ __ `__ \\\n"
           "/ /_/ (__  )  __/ /  __(__  |__  )   ___/ / / / / /_/ / /_/ /   ___/ / /_/ (__  ) /_/  __/ / / / / /\n"
           "\\____/____/\\___/_/\\___/____/____/   /____/_/ /_/\\____/ .___/   /____/\\__, /____/\\__/\\___/_/ /_/ /_/ \n"
           "                                                    /_/             /____/                          \n");
    proc();
    system("cls");
    printf("    ___     __     __       __                      __           __\n"
           "   /   |   / /    / /      / /   ____   ____ _ ____/ /___   ____/ /\n"
           "  / /| |  / /    / /      / /   / __ \\ / __ `// __  // _ \\ / __  / \n"
           " / ___ | / /___ / /___   / /___/ /_/ // /_/ // /_/ //  __// /_/ /  \n"
           "/_/  |_|/_____//_____/  /_____/\\____/ \\__,_/ \\__,_/ \\___/ \\__,_/   \n"
           "                                                                   \n");
    Sleep(500);
    system("cls");
    reminder();
    login();
    system("pause");
    return 0;
}