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
//����
void jitang(){
    int i=rand()%11+1;
    if(i==1)
    {
        printf("�������������ǲ���ǰ����ÿһ�ε�Ŭ������Ϊ��ʵ���Լ���Ŀ������롣\n");
    }
    if(i==2)
    {
        printf("ÿһ��Ŭ�����ǶԳɹ��Ŀ�����������һ�𼤷�����������������ֱǰ��\n");
    }
    if(i==3)
    {
        printf("��Ҫ�ȴ����ᣬ����Ҫ������ᡣ������������������񣬸���Ҫ��Խ���ң�׷��׿Խ��\n");
    }
    if(i==4)
    {
        printf("Ŭ���������������ǳɹ���ϲ�ú��Ժ���������\n");
    }
    if(i==5)
    {
        printf("�ڷܹ�����չ�ֲŻ�����������δ����\n");
    }
    if(i==6)
    {
        printf("���������ǻۣ��������ͻԻ͡�\n");
    }
    if(i==7)
    {
        printf("˭Ը���̤ʵ������ع�����˭���������ܶ�ɼ������ܳ�Ⱥ���ڡ�\n");
    }
    if(i==8)
    {
        printf("ÿһ�ݹ�������һ�λ��ᣬÿһ�λ��ᶼֵ��ȫ���Ը���\n");
    }
    if(i==9)
    {
        printf("����Ӧ����ϧ��ݹ������ü���ͺ�ˮ���������ĳɹ������Լ����ŶӸ���һ��¥��\n");
    }
    if(i==10)
    {
        printf("�����У���Ҫ����ʧ�ܣ�Ҫѧ���ʧ���м�ȡ����ͽ�ѵ��\n");
    }

}

//�������
void reminder(){
    FILE *fp;
    int flag_0=0,flag_1=0;
    int n_year,n_month,n_day;
    int diff;
    while(1){
        //��ȡ����ʱ��
        time_t Curtime = time(NULL);
        struct tm *time_now = localtime(&Curtime);
        struct tm date1={0};
        struct tm date2={0};
        //�ѵ�ǰʱ�����date1
        date1.tm_year=time_now->tm_year;
        date1.tm_mon=time_now->tm_mon;
        date1.tm_mday=time_now->tm_mday;
        //���㵱ǰʱ���ʱ���
        time_t a= mktime(&date1);

        system("cls");
        printf("  ______          __           _          _   __      __           \n"
               " /_  __/___  ____/ /___ ___  _( )_____   / | / /___  / /____  _____\n"
               "  / / / __ \\/ __  / __ `/ / / /// ___/  /  |/ / __ \\/ __/ _ \\/ ___/\n"
               " / / / /_/ / /_/ / /_/ / /_/ / (__  )  / /|  / /_/ / /_/  __(__  ) \n"
               "/_/  \\____/\\__,_/\\__,_/\\__, / /____/  /_/ |_/\\____/\\__/\\___/____/  \n"
               "                      /____/                                       \n");
        printf("----------------------------------------------------------------\n");

        //���漱����

        if((fp= fopen("..\\data\\products_data.txt","r"))==NULL){
            break;
        }

        fread(&products_list, sizeof(products ),1,fp);
        while(!feof(fp)){
            if(products_list.num<10){
                printf("%s\t%s <<<��ǰ��Ʒ��漴������(��ǰ%d��)���뼰ʱ����������\n",
                       products_list.id,products_list.name,products_list.num);
                flag_0=1;
            }
            else if(products_list.num<50){
                printf("%s\t%s <<<��ǰ��Ʒ�Ѳ���50��(��ǰ%d��)���뼰ʱ����������\n",
                       products_list.id,products_list.name,products_list.num);
                flag_0=1;
            }
            else if(products_list.num<100){
                printf("%s\t%s <<<��ǰ��Ʒ�Ѳ���100��(��ǰ%d��)���뼰ʱ����������\n",
                       products_list.id,products_list.name,products_list.num);
                flag_0=1;
            }

            fread(&products_list, sizeof(products ),1,fp);
        }
        fclose(fp);

        if(flag_0 != 1){
            printf("���޿�治����Ϣ!!!\n");
        }
        else{
            printf("---------------------------------\n");
            printf("���֪ͨ������!!!\n");
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



        //��Ʒ��������
        if((fp= fopen("..\\data\\products_data.txt","r"))==NULL){
            printf("��ȡ�ļ�ʧ��\n");
            system("pause");
        }
        fread(&products_list, sizeof(products ),1,fp);
        while(!feof(fp)){
            //����Ʒ�������ڸ���date2
            date2.tm_year=products_list.data.year-1900;
            date2.tm_mon=products_list.data.month-1;
            date2.tm_mday=products_list.data.day;
            //������Ʒ�������ڵ�ʱ���
            time_t b= mktime(&date2);
            //����ʱ���������ʱ��õ����ڲ�
            diff= (int)difftime(a,b)/(60*60*24);
            if(diff>products_list.exp){
                printf("%s\t%s <<<��ǰ��Ʒ�ѹ���(����%d��)���뼰ʱ��������\n",
                       products_list.id,products_list.name,diff-products_list.exp);
                flag_1=1;
            }
            else if(diff>products_list.exp-7){
                printf("%s\t%s <<<��ǰ��Ʒ��Ҫ������(ʣ��%d��)����ע�⣡����\n",
                       products_list.id,products_list.name,7);
                flag_1=1;
            }
            else if(diff>products_list.exp-15){
                printf("%s\t%s <<<��ǰ��Ʒ��Ҫ������(ʣ��%d��)����ע�⣡����\n",
                       products_list.id,products_list.name,15);
                flag_1=1;
            }
            else if(diff>products_list.exp-30){
                printf("%s\t%s <<<��ǰ��Ʒ��Ҫ������(ʣ��%d��)����ע�⣡����\n",
                       products_list.id,products_list.name,30);
                flag_1=1;
            }

            fread(&products_list, sizeof(products ),1,fp);
        }
        fclose(fp);
        if(flag_1 != 1){
            printf("***���޹���������Ϣ!!!***\n");
        }
        else{
            printf("---------------------------------\n");
            printf("��������������!!!\n");
        }
        system("pause");
        system("cls");
        break;
    }

}
//������
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
//��ȡʱ��
void print_Currenttime(){
    //��ȡ��ǰʱ��
    //���������Զ���¼���ʱ��ͼ�����Ʒ�Ƿ����
    time_t Curtime = time(NULL);
    struct tm *ptm= localtime(&Curtime);
    printf("������%d��%d��%d��,%d:%d:%d\n",ptm->tm_year+1900,ptm->tm_mon+1,ptm->tm_mday,
           ptm->tm_hour,ptm->tm_min,ptm->tm_sec);

}
//��¼ϵͳ
void login(){
    //��¼ϵͳ������Ȩ
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
        printf("��ѡ���¼��ʽ:\n1.Ա��\n2.����Ա\n3.�һ�����\n4.�˳�����\n");
        printf(">>> ");
        scanf("%d",&choice);
        //��ȡԱ���ļ�
        FILE *fp;
        if((fp= fopen("..\\data\\emp_data.txt","r"))==0){
            printf("��ȡԱ����Ϣʧ�ܣ�");
            system("pause");
            continue;
        }
        //��Ա���ļ��е���Ϣд�뻺��emp_temp[N];
        //��������(�ж��˺��Ƿ���ڣ��ж��Ƿ�Ϊ����Ա)�ڻ����н���
        fread(&emp_list,sizeof (emp),1,fp);
        while (!feof(fp)){
            emp_temp[i]=emp_list;
            i++;
            fread(&emp_list,sizeof (emp),1,fp);
        }
        fclose(fp);

        if(choice==1){
            printf("���������ı��:");
            scanf("%s",input_id);
            printf("��������������:");
            scanf("%s",input_password);

            //ƥ�������id���ļ��д��ڵ�id

            for(k=0;k<i;k++){
                //��������������ת
                if((strcmp(input_id,emp_temp[k].id)==0 && strcmp(input_password,emp_temp[k].password)==0 && emp_temp[k].chance<1)
                    ||(strcmp(input_id,emp_temp[k].id)==0 && emp_temp[k].chance<1)){
                    printf("�˺����������һ�����\n");
                    flag=1;
                    system("pause");
                    break;
                }

                else if(strcmp(input_id,emp_temp[k].id)==0 && strcmp(input_password,emp_temp[k].password)==0){
                    if(emp_temp[k].chance>=1){
                        printf("��½�ɹ���\n");
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
                    printf("�������!ʣ��%d�λ���!!!\n",emp_temp[k].chance);
                    system("pause");

                }
            }
            //������ִ�е����������Ϣ
            if(flag==0){
                printf("�˺Ŵ������������123!\n");
                system("pause");
                continue;
            }


        }
        else if(choice==2){
            printf("���������ı��:");
            scanf("%s",input_id);
            printf("��������������:");
            scanf("%s",input_password);
            //���һ����������
            for(k=0;k<i;k++){
                if(strcmp(input_id,emp_temp[k].id)==0 && strcmp(input_password,emp_temp[k].password)==0){
                    if(emp_temp[k].admin==1){
                        printf("��½�ɹ���\n");
                        system("pause");
                        menu_admin_0();
                    }
                    else{
                        printf("�����ǹ���Ա!\n");
                        system("pause");
                        continue;
                    }

                }
            }

            printf("�˺Ż�����������������!\n");
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
            printf("ѡ�����!");
            system("pause");
        }
    }

}
//�һ�����
void findback(){
    FILE *fp;
    int flag;
    int i,j;
    char a[10];//�˺�
    char name[15];//����
    char password_1[11],password_2[11];
    char n[15];//�绰��
    char color[15];//��ɫ
    char eat[20];//ʳ��
    char place[50];//סַ
    while(1){
        flag=0;
        i=0;
        getchar();
        printf("�����������˺ţ�");
        gets(a);
        printf("�������˺������ߵ�������");
        gets(name);
        /*printf("�������˺������ߵ����֤�ţ�");
        gets(num);*/
        printf("�������˺������ߵĵ绰��");
        gets(n);
        printf("�������˺�������ϲ������ɫ��");
        gets(color);
        printf("�������˺������ߵ�ϲ����ʳ�");
        gets(eat);
        printf("�������˺������ߵ�סַ��");
        gets(place);
        system("cls");
        //���ļ�
        fp=fopen("..\\data\\emp_data.txt","r");
        if(fp==NULL)
        {
            printf("��ʧ��");
            system("pause");
            break;
        }
        //д�뻺��
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
                printf("���������µ����룺");
                scanf("%s",password_1);
                system("cls");
                printf("���ٴ��������������룺");
                scanf("%s",password_2);
                if(strcmp(password_1,password_2)==0)
                {
                    fp=fopen("..\\data\\emp_data.txt","w");
                    if(fp==NULL)
                    {
                        printf("��ʧ��");
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
                    printf("�޸����\n");
                }
                else
                {
                    printf("�������벻һ��,������\n");
                    continue;
                }
            }
            else{
                printf("�һ�����ʧ�ܣ������˺��ѳ��������������������ϵϵͳ����Ա!!!\n");
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

//����
void outbound_menu(){
    //����ϵͳ�˵�
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
        printf("1.��Ʒ����\n2.��Աϵͳ\n3.����ѯ\n4.�˳���¼\n5.�˳�����\n");
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
            printf("1.ȫ�����\n2.ָ����ѯ\n");
            printf(">>> ");
            scanf("%d",&choice);
            //ֱ�ӵ���д�õ���Ʒ�������
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
            printf("ѡ������!\n");
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
        printf("����Ҫ�������Ʒid(ģ��ɨ��):");
        scanf("%s",input_id);


        if((fp=fopen("..\\data\\products_data.txt","r"))==NULL){
            printf("�ļ���ȡʧ�ܣ�������(05)\n");
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

        //�򿪳������ļ�����д�뵱ǰ������Ϣ
        if((fp=fopen("..\\data\\list_data.txt","ab"))==NULL){
            printf("�ļ���ʼ��ʧ�ܣ�������(05)\n");
            system("pause");
            break;
        }

        for(k=0;k<i;k++){
            if(strcmp(input_id,pro_temp[k].id)==0){
                printf("-------------�ҵ���Ʒ��Ϣ����-------------\n");
                printf("���\t    ����\t    ����\t     �ۼ�\t    ����\t     ��������\t      ������(day)\t  ���\t\n");
                printf("%s\t    %-10s\t    %-5.2f\t     %-5.2f\t    %-10s\t     %d-%d-%d\t      %-10d\t  %d\t",pro_temp[k].id,pro_temp[k].name,
                       pro_temp[k].price_in,pro_temp[k].price_out,pro_temp[k].addr,
                       pro_temp[k].data.year,pro_temp[k].data.month,pro_temp[k].data.day,
                       pro_temp[k].exp,pro_temp[k].num);
                printf("�������������:");
                scanf("%d",&num);
                strcpy(listTemp.name,pro_temp[k].name);
                listTemp.price=pro_temp[k].price_out;
                if(num<=pro_temp[k].num){
                    listTemp.num=num;
                    pro_temp[k].num-=num;   //�����п�����
                }
                else
                {
                    printf("��Ʒ��治��,����Ʒ��ǰ����:%d ��\n",pro_temp[k].num);
                    printf("������\n");
                    flag=1;
                    continue;
                }
                flag=1;
                fwrite(&listTemp,sizeof (list_temp),1,fp);
            }
        }
        if(flag!=1){
            printf("δ�ҵ�����Ʒ��Ϣ,���ֶ�������\n");
            printf(">>> ");
            scanf("%lf",&price);

            printf("����������\n");
            printf(">>> ");
            scanf("%d",&num);
            strcpy(listTemp.name,"δʶ����Ʒ");
            listTemp.num=num;
            listTemp.price=price;
            fwrite(&listTemp,sizeof (list_temp),1,fp);
        }
        fclose(fp);

        //�ѿ�����д���ļ�
        fp= fopen("..\\data\\products_data.txt","w");
        for(k=0;k<i;k++){
            fwrite(&pro_temp[k],sizeof(products),1,fp);
        }
        fclose(fp);

        printf("������? 1.Yes\\2.No\n");
        scanf("%d",&choice);
        if(choice==1){
            continue;
        }
        else{
            printf("������������\n");
            x = (int)print_outbound_list();
        }


        //�����Զ���¼
        printf("�Ƿ��л�Ա�˻�\n");
        printf("1.��\n");
        printf("2.��\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("�������Ա�˻���");
            scanf("%s",input_phone);
            fp=fopen("..\\data\\vip_data.txt","r");
            if(fp==NULL)
            {
                printf("��ʧ��");
                system("pause");
                break;
            }
            i=0;
            fread(&vip_list, sizeof(vip), 1, fp);
            while (!feof(fp)) {
                vip_temp[i]=vip_list;
                if (strcmp(vip_temp[i].id, input_phone) == 0) {
                    vip_temp[i].point += x;
                    printf("���λ��%d�����,��%d�����!\n",x,vip_temp[i].point+x);
                }
                i++;
                fread(&vip_list, sizeof(vip), 1, fp);

            }
            fclose(fp);

            fp=fopen("..\\data\\vip_data.txt","w");
            if(fp==NULL)
            {
                printf("��ʧ��");
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
            printf("��ȡ������Ϣʧ��!������!\n");
            system("pause");
            break;
        }
        printf("-------------ȫ����Ϣ����-------------\n");
        printf("����\t\t����\t����\t�ܼ�\t\n");
        fread(&listTemp,sizeof (list_temp),1,fp);
        while(!feof(fp)){

            printf("%-15s\t%.2f\t%d\t%.2f\t\n",listTemp.name,listTemp.price,listTemp.num,listTemp.num*listTemp.price);
            sum_price+=listTemp.price*listTemp.num;
            fread(&listTemp,sizeof (list_temp),1,fp);
        }
        fclose(fp);

        if((fp=fopen("..\\data\\list_data.txt","w"))==NULL){
            printf("�ļ���ʼ��ʧ�ܣ�������(05)\n");
            system("pause");
            break;
        }
        fclose(fp);

        printf("--------------------------\n�ܼ�:%.2f Ԫ\n",sum_price);

        printf("��ӡ����\n");
        system("pause");
        break;
    }
    return sum_price*100;

}

//��Ʒ
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
        printf("\t��ӭʹ�ó�����Ʒ����ϵͳV1.2\n");
        printf("\t   1.������Ʒ��Ϣ����\n");
        printf("\t   2.����Ա����Ϣ����\n");
        printf("\t   3.�˳���¼\n");
        printf("\t   4.�˳�����\n");
        printf("-----------------------------------------\n");
        printf("��ѡ��:");
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
            printf("ѡ�������������������!\n");
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
        printf("\t��ӭʹ�ó�����Ʒ����ϵͳV1.2\n");
        printf("-----------------------------------------\n");
        printf("\t   1.¼����Ʒ��Ϣ\n");
        printf("\t   2.�鿴��Ʒ����\n");
        printf("\t   3.�����ض���Ʒ\n");
        printf("\t   4.�޸��ض���Ʒ\n");
        printf("\t   5.ɾ���ض���Ʒ\n");
        printf("\t   6.������ѡ��\n");
        printf("\t   7.�鿴��������\n");
        printf("\t   8.�˳�����\n");
        printf("-----------------------------------------\n");
        printf("��ѡ��:");
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
            printf("ѡ������!�������������!\n");
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
        printf("\t��ӭʹ�ó�����Ʒ����ϵͳV1.2\n");
        printf("-----------------------------------------\n");
        printf("\t   1.¼��Ա����Ϣ\n");
        printf("\t   2.�鿴Ա������\n");
        printf("\t   3.�����ض�Ա��\n");
        printf("\t   4.�޸�Ա����Ϣ\n");
        printf("\t   5.ɾ��Ա����Ϣ\n");
        printf("\t   6.������ѡ��\n");
        printf("\t   7.�˳�����\n");
        printf("-----------------------------------------\n");
        printf("��ѡ��:");
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
            printf("ѡ������!�������������!\n");
            system("pause");
            menu_admin_2();
        }
    }

}
void add_products(){
    int choice;

    while(1){
        printf("��������Ʒ����:\n");
        scanf("%s", products_list.id);
        printf("��������Ʒ����:\n");
        scanf("%s", products_list.name);
        printf("��������Ʒ����:\n");
        scanf("%lf", &products_list.price_in);
        printf("��������Ʒ�ۼ�:\n");
        scanf("%lf", &products_list.price_out);
        printf("��������Ʒ����:\n");
        scanf("%s", products_list.addr);
        printf("��������Ʒ��������(��ʽ:20xx-xx-xx):\n");
        scanf("%d-%d-%d", &products_list.data.year,&products_list.data.month,&products_list.data.day);
        printf("�����뱣����(day):\n");
        scanf("%d",&products_list.exp);
        printf("��������Ʒ����:\n");
        scanf("%d", &products_list.num);


        printf("���Ա�����Ϣ��......\n");
        FILE *fp;
        if((fp=fopen("..\\data\\products_data.txt","ab"))==NULL){
            printf("�ļ���ʧ�ܣ�������(01)!\n");
            system("pause");
            return;
        }
        fwrite(&products_list,sizeof (products),1,fp);
        fclose(fp);
        printf("����ɹ�!\n");
        printf("¼�����,�Ƿ����¼��?\n1.Yes\\2.No\n");
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
        printf("�ļ���ȡʧ�ܣ�������(02)\n");
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
        printf("�ļ���ȡʧ�ܣ�������(03)\n");
        system("pause");
        menu_admin_1();
    }

    printf("������Ҫɾ������Ʒ�ı��:");
    scanf("%s",input_id);

    for(k=0;k<i;k++){
        if(strcmp(input_id, pro_temp[k].id) == 0){
            printf("ȷ��ɾ����1.Yes\\2.No\n");
            scanf("%d",&choice);
            if(choice==1){
                flag=1;
                printf("ɾ���ɹ�!\n");
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
        printf("δ�ҵ���Ʒ!\n");
        system("pause");
    }
    else if(flag==2){
        printf("ȡ��ɾ��!\n");
        system("pause");
    }
    fclose(fp);
    menu_admin_1();
}
void output_all_products(){
    int choice;
    FILE *fp;
    if((fp=fopen("..\\data\\products_data.txt","r"))==NULL){
        printf("�ļ���ȡʧ�ܣ�������(04)\n");
        system("pause");
        return;
    }

    printf("----------------------------------------------------ȫ����Ϣ����-------------------------------------"
           "-----------------\n");
    printf("���\t    ����\t    ����\t     �ۼ�\t    ����\t     ��������\t      ������(day)\t  ���\t\n");
    fread(&products_list,sizeof (products),1,fp);
    while(!feof(fp)){

        printf("%s\t    %-10s\t    %-5.2f\t     %-5.2f\t    %-10s\t     %d-%d-%d\t      %-10d\t  %d\t\n",
               products_list.id,products_list.name,products_list.price_in,products_list.price_out,
               products_list.addr,products_list.data.year,products_list.data.month,products_list.data.day,
               products_list.exp,products_list.num);
        fread(&products_list,sizeof (products),1,fp);

    }
    fclose(fp);
    printf("��ѯ���,���ز˵�\n");
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
            printf("�ļ���ȡʧ�ܣ�������(05)\n");
            system("pause");
            break;
        }
        system("cls");
        printf("��������ҷ�ʽ:\n");
        printf("1.���\n2.����(ģ��)\n");
        scanf("%d",&choice);
        if(choice==1){
            printf("��������ҵ���Ʒ���:");
            scanf("%s",input_id);
            fread(&products_list,sizeof (products),1,fp);
            while (!feof(fp)){
                if(strcmp(input_id,products_list.id)==0){
                    printf("���ҳɹ�!\n");
                    printf("-------------��Ʒ��Ϣ����-------------\n");
                    printf("���\t    ����\t    ����\t     �ۼ�\t    ����\t     ��������\t      ������(day)\t  ���\t\n");
                    printf("%s\t    %-10s\t    %-5.2f\t     %-5.2f\t    %-10s\t     %d-%d-%d\t      %-10d\t  %d\t\n",products_list.id,
                           products_list.name,products_list.price_in,products_list.price_out,
                           products_list.addr,products_list.data.year,products_list.data.month,
                           products_list.data.day,products_list.exp,products_list.num);
                    flag=1;
                }
                fread(&products_list,sizeof (products),1,fp);
            }
            if(flag!=1){
                printf("δ�ҵ�����Ʒ!����������ѯ!\n");
                system("pause");
            }
        }

        else if(choice==2){
            printf("����������:\n");
            scanf("%s",input_name);
            printf("���\t    ����\t    ����\t     �ۼ�\t    ����\t     ��������\t      ������(day)\t  ���\t\n");
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
                printf("δ�ҵ���Ϣ!");
            }
        }


        else{
            printf("�������!\n");
            continue;
        }

        fclose(fp);
        printf("Ҫ������ѯ��?1.Yes\\2.NO\n");
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
        printf("�ļ���ʧ�ܣ�������(06)!\n");
        system("pause");
        return;
    }
    printf("������Ҫ�޸ĵ���Ʒ�ı��\n");
    scanf("%s",input_id);
    fread(&products_list,sizeof (products),1,fp);
    while (!feof(fp)){
        if(strcmp(input_id,products_list.id)==0){
            printf("���ҳɹ�!\n");
            printf("-------------��Ʒ��Ϣ����-------------\n");
            printf("��Ʒ���\t����\t����\t�ۼ�\t����\t��������\t������(day)\t���\t\n");
            printf("%s\t\t%s\t%.2f\t%.2f\t%s\t%d-%d-%d\t%d\t%d\t\n",products_list.id,products_list.name,products_list.price_in,
                   products_list.price_out,products_list.addr,products_list.data.year,products_list.data.month,products_list.data.day,products_list.exp,products_list.num);
            flag=1;
        }
        fread(&products_list,sizeof (products),1,fp);
    }
    if(flag!=1){
        printf("δ�ҵ�����Ʒ!������������!\n");
        system("pause");
        fclose(fp);
        edit_products();
    }
    fclose(fp);


    if((fp=fopen("..\\data\\products_data.txt","r"))==NULL){
        printf("�ļ���ʧ�ܣ�������(07)!\n");
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
        printf("�ļ���ʧ�ܣ�������(08)!\n");
        system("pause");
        return;
    }

    for(k=0;k<i;k++){
        if(strcmp(input_id, pro_temp[k].id) == 0){
            printf("����Ҫ�޸�?\n1.����\n2.����\n3.�ۼ�\n4.����\n5.��������\n6.������\n7.����\n");
            scanf("%d",&choice);
            if(choice==1){
                printf("������������:\n");
                scanf("%s",new_name);
                strcpy(pro_temp[k].name, new_name);
                printf("�޸ĳɹ�\n");
            }
            else if(choice==2){
                printf("�������½���:\n");
                scanf("%lf",&new_price);
                pro_temp[k].price_in=new_price;
                printf("�޸ĳɹ�\n");
            }
            else if(choice==3){
                printf("���������ۼ�:\n");
                scanf("%lf",&new_price);
                pro_temp[k].price_out=new_price;
                printf("�޸ĳɹ�\n");
            }
            else if(choice==4){
                printf("�������²���:\n");
                scanf("%s",new_addr);
                strcpy(pro_temp[k].addr,new_addr);
                printf("�޸ĳɹ�\n");
            }
            else if(choice==5){
                printf("����������������(20xx-x-x):\n");
                scanf("%d-%d-%d", &new_data.year,&new_data.month,&new_data.day);
                pro_temp[k].data=new_data;
                printf("�޸ĳɹ�\n");
            }
            else if(choice==6){
                printf("�������±�����:\n");
                scanf("%d",&new_num);
                pro_temp[k].exp=new_num;
                printf("�޸ĳɹ�\n");
            }
            else if(choice==7){
                printf("������������:\n");
                scanf("%d",&new_num);
                pro_temp[k].num=new_num;
                printf("�޸ĳɹ�\n");
            }
            else{
                printf("�������!���������!\n");
            }

        }
        //��һ��дһ�������޸ĵ��ȱ��޸ĺ���д��ȥ
        fwrite(&pro_temp[k], sizeof (products), 1, fp);

    }
    fclose(fp);
    printf("�����ѱ���\n");
}

//Ա��
void add_emp(){

    int choice;
    while(1){
        //��ȡ��ǰʱ��
        time_t Curtime = time(NULL);
        struct tm *ptm= localtime(&Curtime);
        printf("������Ա������:\n");
        scanf("%s", emp_list.id);
        printf("������Ա������:\n");
        scanf("%s", emp_list.name);
        printf("������Ա���Ա�:\n");
        scanf("%s", emp_list.gender);
        /*
        printf("������Ա����ְ����(20xx-x-x):\n");
        scanf("%d-%d-%d", &emp_list.data.year,&emp_list.data.month,&emp_list.data.day);
        */
        emp_list.data.year=ptm->tm_year+1900;
        emp_list.data.month=ptm->tm_mon+1;
        emp_list.data.day=ptm->tm_mday;

        printf("��ΪԱ����ʼ��ϵͳ����(<10λ��):\n");
        scanf("%s", emp_list.password);
        printf("�Ƿ�Ҫ�����û���Ϊ����Ա��1.Yes\\2.NO\n");
        scanf("%d",&choice);
        if(choice==1){
            emp_list.admin=1;
        }
        else{
            emp_list.admin=0;
        }
        //¼���һ���������Ҫ����Ϣ
        printf("���������ܱ�����\n");
        printf("�����������ֻ�����\n>>> ");
        scanf("%s",emp_list.phone);
        printf("��������ϲ������ɫ\n>>> ");
        scanf("%s",emp_list.color);
        printf("��������ϲ����ʳ��\n>>> ");
        scanf("%s",emp_list.food);
        printf("���������ļ�ͥסַ\n>>> ");
        scanf("%s",emp_list.addr);
        emp_list.chance=3;//����������
        emp_list.state=0;//�˺��Ƿ�����Ĭ��0δ��
        printf("���Ա�����Ϣ��......\n");
        FILE *fp;
        if((fp=fopen("..\\data\\emp_data.txt","ab"))==NULL){
            printf("�ļ���ʧ�ܣ�������(01)!\n");
            system("pause");
            return;
        }
        fwrite(&emp_list,sizeof (emp),1,fp);
        fclose(fp);
        printf("����ɹ�!\n");
        printf("¼�����,�Ƿ����¼��?\n1.Yes\\2.No\n");
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
        printf("�ļ���ȡʧ�ܣ�������(02)\n");
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
        printf("�ļ���ȡʧ�ܣ�������(03)\n");
        system("pause");
        menu_admin_2();
    }

    printf("������Ҫɾ����Ա���ı��:");
    scanf("%s",input_id);

    for(k=0;k<i;k++){
        if(strcmp(input_id, emp_temp[k].id) == 0){
            printf("ȷ��ɾ����1.Yes\\2.No\n");
            scanf("%d",&choice);
            if(choice==1){
                flag=1;
                printf("ɾ���ɹ�!\n");
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
        printf("δ�ҵ���Ա��!\n");
        system("pause");
    }
    else if(flag==2){
        printf("ȡ��ɾ��!\n");
        system("pause");
    }
    fclose(fp);
    menu_admin_2();
}
void output_all_emp(){
    int choice;
    FILE *fp;
    if((fp=fopen("..\\data\\emp_data.txt","r"))==NULL){
        printf("�ļ���ȡʧ�ܣ�������(04)\n");
        system("pause");
        return;
    }

    printf("-------------ȫ����Ϣ����-------------\n");
    printf("Ա�����\t����\t�Ա�\t��ְ����\t����Ա\t\n");

    fread(&emp_list,sizeof (emp),1,fp);
    while(!feof(fp)){

        printf("%s\t\t%s\t%s\t%d-%d-%d\t",emp_list.id,emp_list.name,emp_list.gender,
               emp_list.data.year,emp_list.data.month,emp_list.data.day);
        if(emp_list.admin==1){

            printf("��\t\n");

        }
        else{

            printf("��\t\n");

        }

        fread(&emp_list,sizeof (emp),1,fp);

    }
    fclose(fp);
    printf("��ѯ���,���ز˵�\n");
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
        printf("�ļ���ȡʧ�ܣ�������(05)\n");
        system("pause");
        return;
    }
    system("cls");
    printf("��������ҷ�ʽ:\n");
    printf("1.���\n2.����(ģ��)\n");
    scanf("%d",&choice);
    if(choice==1){
        printf("��������ҵ�Ա�����:");
        scanf("%s",input_id);
        fread(&emp_list,sizeof (emp),1,fp);
        while (!feof(fp)){
            if(strcmp(input_id,emp_list.id)==0){
                printf("���ҳɹ�!\n");
                printf("-------------Ա����Ϣ����-------------\n");
                printf("Ա�����\t����\t�Ա�\t��ְ����\t\n");
                printf("%s\t\t%s\t%s\t%d-%d-%d\n",emp_list.id,emp_list.name,emp_list.gender,
                       emp_list.data.year,emp_list.data.month,emp_list.data.day);
                flag=1;
            }
            fread(&emp_list,sizeof (emp),1,fp);
        }
        if(flag!=1){
            printf("δ�ҵ���Ա��!����������ѯ!\n");
            system("pause");
        }
    }
    else if(choice==2){
        printf("��������Ϣ:\n");
        scanf("%s",input_name);
        printf("Ա�����\t����\t�Ա�\t��ְ����\t\n");
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
            printf("δ�ҵ��κ���Ϣ!\n");
        }
    }
    else{
        printf("�������!\n");
        serch_emp();
    }

    fclose(fp);
    printf("Ҫ������ѯ��?1.Yes\\2.NO\n");
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
        printf("�ļ���ʧ�ܣ�������(06)!\n");
        system("pause");
        return;
    }
    printf("������Ҫ�޸ĵ�Ա���ı��\n");
    scanf("%s",input_id);
    fread(&emp_list,sizeof (emp),1,fp);
    while (!feof(fp)){
        if(strcmp(input_id,emp_list.id)==0){
            printf("���ҳɹ�!\n");
            printf("-------------Ա����Ϣ����-------------\n");
            printf("Ա�����\t����\t�Ա�\t��ְ����\t����Ա\t\n");
            printf("%s\t\t%s\t%s\t%d-%d-%d\t",emp_list.id,emp_list.name,emp_list.gender,
                   emp_list.data.year,emp_list.data.month,emp_list.data.day);
            if(emp_list.admin==1){

                printf("��\t\n");

            }
            else{

                printf("��\t\n");

            }
            flag=1;
        }
        fread(&emp_list,sizeof (emp),1,fp);
    }
    fclose(fp);
    if(flag!=1){
        printf("δ�ҵ���Ա��!������������!\n");
        system("pause");
        menu_admin_2();

    }


    if((fp=fopen("..\\data\\emp_data.txt","r"))==NULL){
        printf("�ļ���ʧ�ܣ�������(07)!\n");
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
        printf("�ļ���ʧ�ܣ�������(08)!\n");
        system("pause");
        return;
    }
    for(k=0;k<i;k++){
        if(strcmp(input_id, emp_temp[k].id) == 0){
            printf("����Ҫ�޸�?\n1.����\n2.�Ա�\n3.��ְ����\n4.��¼����\n5.�л�����Ա״̬\n");
            scanf("%d",&choice);
            if(choice==1){
                scanf("%s",new_name);
                strcpy(emp_temp[k].name, new_name);
                printf("�޸ĳɹ�\n");
            }
            else if(choice==2){
                scanf("%s",new_gender);
                strcpy(emp_temp[k].gender, new_gender);
                printf("�޸ĳɹ�\n");
            }

            else if(choice==3){
                scanf("%d-%d-%d", &new_data.year,&new_data.month,&new_data.day);
                emp_temp[k].data=new_data;
                printf("�޸ĳɹ�\n");

            }
            else if(choice==4){
                scanf("%s", new_password);
                strcpy(emp_temp[k].password, new_password);
                printf("�޸ĳɹ�\n");

            }
            else if(choice==5){
                printf("1.�趨����Ա\n2.ȡ������Ա\n");
                printf("��ѡ��>>>");
                scanf("%d",&choice);
                if(choice==1){
                    emp_temp[k].admin=1;
                    printf("�޸ĳɹ�\n");

                }
                else if(choice==2){
                    emp_temp[k].admin=0;
                    printf("�޸ĳɹ�\n");

                }
                else{
                    printf("ѡ������!\n");
                }
            }

            else{
                printf("�������!���������!\n");
            }

        }
        //��һ��дһ�������޸ĵ��ȱ��޸ĺ���д��ȥ
        fwrite(&emp_temp[k], sizeof (emp), 1, fp);

    }
    fclose(fp);
}

//��Ա����
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
        printf("1.ע���Ա�˺�\n2.��ѯ��Ա����\n3.�鿴���л�Ա�˺�\n4.�޸��˺���Ϣ\n5.������Ա����\n6.�˳�\n");
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
            printf("��ʼ���ļ�ʧ��!\n");
            break;
        }
        printf("���������ĵ绰����:\n");
        scanf("%s",input_number);
        printf("������һ������:\n");
        scanf("%s",input_password);
        strcpy(vip_list.id,input_number);
        strcpy(vip_list.password,input_password);
        vip_list.point=0;
        fwrite(&vip_list, sizeof(vip ),1,fp);
        fclose(fp);
        printf("�����ɹ�!\n");
        system("pause");
        break;
    }

}
void output_all_vip(){
    FILE *fp;
    if((fp= fopen("..\\data\\vip_data.txt","r"))==NULL){
        printf("���ļ�ʧ��!\n");
        system("pause");
        return;
    }
    printf("�˺�\t\t����\t����\t\n");
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
            printf("���ļ�ʧ��!\n");
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

        printf("������Ҫ�޸ĵ��˺�:");
        scanf("%s",input_id);
        for(k=0;k<i;k++){
            if(strcmp(input_id,vip_temp[k].id)==0){
                printf("1.�˺�\n2.����\n3.����\n");
                scanf("%d",&choice);
                if(choice==1){
                    printf("�������µ��˺�:");
                    scanf("%s",new_id);
                    strcpy(vip_temp[k].id,new_id);
                    printf("�޸ĳɹ�");
                }
                else if(choice==2){
                    printf("�������µ�����:");
                    scanf("%s",new_password);
                    strcpy(vip_temp[k].password,new_password);
                    printf("�޸ĳɹ�");

                }
                else if(choice==3){
                    printf("�������µĻ���:");
                    scanf("%d",&new_point);
                    vip_temp[k].point=new_point;
                    printf("�޸ĳɹ�");

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
            printf("��ʼ���ļ�ʧ��!\n");
            break;
        }

        printf("�������˺�:\n");
        scanf("%s",input_number);
        fread(&vip_list,sizeof(vip),1,fp);
        while(!feof(fp)){
            if(strcmp(input_number,vip_list.id)==0){
                printf("����%d�����\n",vip_list.point);
                flag=1;
            }
            fread(&vip_list,sizeof(vip),1,fp);
        }
        fclose(fp);
        if(flag!=1){
            printf("δ�ҵ����˺�\n");
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
            printf("��ȡ�ļ�ʧ��!\n");
            break;
        }
        printf("����������˺�:");
        scanf("%s",input_number);
        /*fread(&vip_list, sizeof(vip ),1,fp);
        while(!feof(fp)){
            if(strcmp(input_number,vip_list.id)==0){
                printf("����%d�����\n",vip_list.point);
                if(input_point<=vip_list.point){
                    printf("����������:");
                    scanf("%s",input_password);
                    if(strcmp(input_password,vip_list.password)==0){
                        new_point=vip_list.point-input_point;
                        printf("�۳����,ʣ��%d������\n",new_point);
                    }
                    else{
                        printf("�������!���������");
                    }
                }
                else{
                    printf("������������!\n");
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
            printf("���ļ�ʧ��!\n");
            break;
        }

        for(k=0;k<i;k++){
            if(strcmp(input_number,vip_temp[k].id)==0){
                printf("����%d�����\n",vip_temp[k].point);
                printf("�������������:");
                scanf("%d",&input_point);
                printf("����������:");
                scanf("%s",input_password);
                if(input_point<=vip_temp[k].point){

                    if(strcmp(input_password,vip_temp[k].password)==0){
                        new_point=vip_temp[k].point-input_point;
                        printf("�۳����,ʣ��%d������\n",new_point);
                        vip_temp[k].point=new_point;
                    }
                    else{
                        printf("�������!���������");
                    }
                }
                else{
                    printf("���ֲ���!!!\n");
                }
                flag=1;
            }
            fwrite(&vip_temp[k], sizeof(vip ),1,fp);
        }
        fclose(fp);
        if(flag!=1){
            printf("δ�ҵ����˺�!\n");
        }
        system("pause");
        break;
    }

}

int main(){
    int choice;
    time_t Curtime = time(NULL);
    struct tm *ptm= localtime(&Curtime);
    //����Ƿ��ǵ�һ��ʹ�ó���Ĭ�ϴ���һ������Ա�˺�
    FILE *fp;
    if((fp=fopen("..\\data\\emp_data.txt","r"))==NULL){
        fclose(fp);
        printf("��鵽���ǳ���ʹ�ã����潫����������һ������Ա�˻�\n�˺�Ĭ��id:10001\n");
        //printf("������Ա������:\n");
        //scanf("%s", emp_list.id);
        strcpy(emp_list.id,"10001");
        //printf("���������Ա�˺�:\n");
        //scanf("%s", emp_list.name);
        strcpy(emp_list.name,"Admin");
        //printf("������Ա���Ա�:\n");
        //scanf("%s", emp_list.gender);
        //strcpy(emp_list.gender,"");
        //printf("������Ա����ְ����(20xx-x-x):\n");
        //scanf("%d-%d-%d", &emp_list.data.year,&emp_list.data.month,&emp_list.data.day);
        emp_list.chance=3;
        emp_list.data.year=ptm->tm_year+1900;
        emp_list.data.month=ptm->tm_mon+1;
        emp_list.data.day=ptm->tm_mday;
        strcpy(emp_list.gender,"NULL");
        printf("��Ϊ��ʼ������Ա����(<10λ��):\n");
        scanf("%s", emp_list.password);
        emp_list.admin=1;
        emp_list.state=0;
        printf("���Ա�����Ϣ��......\n");
        if((fp=fopen("..\\data\\emp_data.txt","ab"))==NULL){
            printf("�ļ�����ʧ�ܣ�������(01)!\n");
            system("pause");
        }
        fwrite(&emp_list,sizeof (emp),1,fp);
        fclose(fp);
        printf("����ɹ�!\n");
        printf("!!!�ù���Ա�˺��޷����������һأ������Ʊ���������Ϣ!!!\n");
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