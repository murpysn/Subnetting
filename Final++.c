#include <stdio.h>
#include <math.h>

void kelasA (int,int[]);
void kelasB (int,int[]);
void kelasC (int,int[]);
void seluruh (int,int[]);

int pangkat,subnet,mask,iptot,host;
int i,x;
main()
{
    int ip[4],prefix;
    char tanyaseluruh,tanyalagi;

    printf(" ---------------------------------------\n");
    printf("|\tPROGRAM MENGHITUNG IP ADDRESS\t|\n");
    printf(" ---------------------------------------\n");
dress:
    printf("\nMasukkan IP Address\n");
        for(i=0;i<4;i++)
            {
                printf("Oktet ke-%d = ",i+1);
                scanf("%d",&ip[i]);
                if(ip[i]>=256)
                {system("cls");printf("IP Address hanya dari 0-255 per Oktet\n");goto dress;}
            }
pref:
    printf("\nMasukkan Prefix [8-30] = /");
        scanf("%d",&prefix);

system("cls");
    if(prefix>=8&&prefix<=15)
        kelasA(prefix,ip);
    else if(prefix>=16&&prefix<=23)
        kelasB(prefix,ip);
    else if(prefix>=24&&prefix<=30)
        kelasC(prefix,ip);
    else
    {
        printf("Prefix yang Anda masukkan salah!!!\n\n");
        goto pref;
    }
fflush(stdin);
    printf("\n\nApakah Anda ingin melihat seluruh perhitungan prefix /%d [y/t] ? ",prefix);
    scanf("%c",&tanyaseluruh);
    if(tanyaseluruh=='y')
    {
        system("cls");
        seluruh(prefix,ip);
    }

fflush(stdin);
    printf("\n\nApakah Anda ingin menghitung lagi [y/t] ?");
    scanf("%c",&tanyalagi);
    if(tanyalagi=='y')
    {
        system("cls");
        return main();
    }
    else if(tanyalagi=='t')
        printf("Terima Kasih!!!");
getch();
}

void kelasA(int prefix, int ip[])
{
    printf("Kelas\t = A\n");

    pangkat=16-prefix;
    subnet=pow(2,pangkat);
    mask=256-subnet;
        printf("NETMASK\t = 255.%d.0.0\n",mask);

    iptot=pow(2,(32-prefix));
        printf("IPTOTAL\t = %d\n",iptot);

    host=iptot-2;
        printf("IPVALID\t = %d\n",host);
system("pause");
    printf("\nIP\t\t = %d.%d.%.d.%d/%d",ip[0],ip[1],ip[2],ip[3],prefix);

    printf("\nNetwork\t\t = ");
        x=0;
        for(i=subnet;i<=256;i=i+subnet)
        {
            if (ip[1]>=x&&ip[1]<i)
                {printf("%d.%d.0.0",ip[0],x);}
            x+=subnet;
        }

    printf("\nRange IP\t = ");
        x=0;
        for(i=subnet;i<=256;i=i+subnet)
        {
            if (ip[1]>=x&&ip[1]<i)
                {printf("%d.%d.0.1",ip[0],x);}
            x+=subnet;
        }
        printf(" - ");
            x=0;
            for(i=subnet;i<=256;i=i+subnet)
            {
                if (ip[1]>=x&&ip[1]<i)
                    {printf("%d.%d.255.254",ip[0],i-1);}
                x+=subnet;
            }

    printf("\nBroadcast\t = ");
        x=0;
        for(i=subnet;i<=256;i=i+subnet)
        {
             if (ip[1]>=x&&ip[1]<i)
                {printf("%d.%d.255.255",ip[0],i-1);}
            x+=subnet;
        }
}

void kelasB(int prefix, int ip[])
{
    printf("Kelas\t = B\n");

    pangkat=24-prefix;
    subnet=pow(2,pangkat);
    mask=256-subnet;
        printf("NETMASK\t = 255.255.%d.0\n",mask);

    iptot=pow(2,(32-prefix));
        printf("IPTOTAL\t = %d\n",iptot);

    host=iptot-2;
        printf("IPVALID\t = %d\n",host);

system("pause");
    printf("\nIP\t\t = %d.%d.%d.%d/%d",ip[0],ip[1],ip[2],ip[3],prefix);

    printf("\nNetwork\t\t = ");
        x=0;
        for(i=subnet;i<=256;i=i+subnet)
        {
            if (ip[2]>=x&&ip[2]<i)
                {printf("%d.%d.%d.0",ip[0],ip[1],x);}
            x+=subnet;
        }

    printf("\nRange IP\t = ");
        x=0;
        for(i=subnet;i<=256;i=i+subnet)
        {
            if (ip[2]>=x&&ip[2]<i)
                {printf("%d.%d.%d.1",ip[0],ip[1],x);}
            x+=subnet;
        }
        printf(" - ");
            x=0;
            for(i=subnet;i<=256;i=i+subnet)
            {
                if (ip[2]>=x&&ip[2]<i)
                    {printf("%d.%d.%d.254",ip[0],ip[1],i-1);}
                x+=subnet;
            }

    printf("\nBroadcast\t = ");
        x=0;
        for(i=subnet;i<=256;i=i+subnet)
        {
            if (ip[2]>=x&&ip[2]<i)
                {printf("%d.%d.%d.255",ip[0],ip[1],i-1);}
            x+=subnet;
        }
}

void kelasC(int prefix,int ip[])
{
    printf("Kelas\t = C\n");

    pangkat=32-prefix;
    subnet=pow(2,pangkat);
    mask=256-subnet;
        printf("NETMASK\t = 255.255.255.%d\n",mask);
        printf("IPTOTAL\t = %d\n",subnet);
    host=subnet-2;
        printf("IPVALID\t = %d\n",host);

system("pause");
    printf("\nIP\t\t = %d.%d.%d.%d/%d",ip[0],ip[1],ip[2],ip[3],prefix);

    printf("\nNetwork\t\t = ");
        x=0;
        for(i=subnet;i<=256;i=i+subnet)
        {
            if (ip[3]>=x&&ip[3]<i)
                {printf("%d.%d.%d.%d",ip[0],ip[1],ip[2],x);}
            x+=subnet;
        }

    printf("\nRange IP\t = ");
        x=0;
        for(i=subnet;i<=256;i=i+subnet)
        {
             if (ip[3]>=x&&ip[3]<i)
                {printf("%d.%d.%d.%d",ip[0],ip[1],ip[2],x+1);}
            x+=subnet;
        }
        printf(" - ");
            x=0;
            for(i=subnet;i<=256;i=i+subnet)
             {
                if (ip[3]>=x&&ip[3]<i)
                    {printf("%d.%d.%d.%d",ip[0],ip[1],ip[2],i-2);}
                x+=subnet;
             }

    printf("\nBroadcast\t = ");
        x=0;
        for(i=subnet;i<=256;i=i+subnet)
        {
            if (ip[3]>=x&&ip[3]<i)
                {printf("%d.%d.%d.%d",ip[0],ip[1],ip[2],i-1);}
            x+=subnet;
        }
}

void seluruh(int prefix,int ip[])
{
    int broad;

    printf("\nRange IP\n");
    if(prefix>=8&&prefix<=15)
    {
        pangkat=16-prefix;
        subnet=pow(2,pangkat);
        x=0;
        do {
            printf("%d.%d.0.0\t",ip[0],x);
            x = x + subnet;
            broad = x - 1;
            printf(" - \t%d.%d.255.255\n",ip[0],broad);
        } while (x<=255);
    }

    else if(prefix>=16&&prefix<=23)
    {
        pangkat=24-prefix;
        subnet=pow(2,pangkat);
        x=0;
        do {
            printf("%d.%d.%d.0\t",ip[0],ip[1],x);
            x = x + subnet;
            broad = x - 1;
            printf(" - \t%d.%d.%d.255\n",ip[0],ip[1],broad);
        } while (x<=255);
    }

    else if(prefix>=24&&prefix<=30)
    {
        pangkat=32-prefix;
        subnet=pow(2,pangkat);
        x=0;
        do {
            printf("%d.%d.%d.%d\t",ip[0],ip[1],ip[2],x);
            x = x + subnet;
            broad = x - 1;
            printf(" - \t%d.%d.%d.%d\n",ip[0],ip[1],ip[2],broad);
        } while (x<=255);
    }
}
