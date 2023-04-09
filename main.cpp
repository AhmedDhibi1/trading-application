#include <iostream>
#include <string>

using namespace std;
class date
{
  private:
    int jour  ;
    int mois  ;
    int annee ;
  public:
    void incrementerdate();
    void transformerdate();
    void afficherdate();
    void setjour(int j);
    void setmois(int m);
    void setannee(int a);
    int getjour();
    int getmois();
    int getannee();
    date(int j ,int m ,int a);

};
int date::getjour()
{
    return jour;
}
int date::getmois()
{
    return mois;
}
int date::getannee()
{
    return annee;
}
void date::setjour(int new_jour)
{
    jour=new_jour ;
}
void date::setmois(int new_mois)
{
    mois=new_mois ;
}
void date::setannee(int new_annee)
{
    annee= new_annee;
}
void date::incrementerdate()
{
    if((mois==1|| mois==3|| mois==5 ||mois== 7 || mois==8 || mois== 10) && (jour==31)){
       mois++;
       jour=1;
    }
    else if((mois==4 || mois==6 || mois==9 || mois==11)&&(jour==30)){

            mois++;
            jour=1;

    }
    else if(mois==12 && jour==31)
    {
        jour=1;
        mois=1;
        annee++;
    }
    else if(mois==2){
        if(jour==28){
            if(annee==2012||annee==2016){
                jour++;
            }
            else{
                mois++;
                jour=1;
            }
        }
        else if(jour==29){
            if(annee==2012||annee==2016){
                mois++;
                jour=1;
            }
            else{
                cout<<"ERROR"<<endl;
            }
        }
        else if(jour>29){
            cout<<"error"<<endl;
        }
    }


    else if((mois==1|| mois==3|| mois==5 ||mois== 7 || mois==8 || mois== 10 || mois==12) && (jour<31)&&(jour>0)){
        jour++;
    }
    else if((mois==4 || mois==6 || mois==9 || mois==11)&&(jour<30)&&(jour>0)){
        jour++;
    }
    else if((annee==2012 || annee==2016) &&(mois==2)&&(jour<29)&&(jour>0)){
        jour++;
    }
     else if ((annee!=2012 || annee!=2016) &&(mois==2)&&(jour<28)&&(jour>0)){
        jour++;
     }
     else{
        cout<<"ERROR"<<endl;
     }

}
void date::afficherdate()
{
    string ch_jour=to_string(jour);
    string ch_mois=to_string(mois);
    string ch_annee=to_string(annee);
    cout<<"la date est : "<<ch_jour<<"/"<<ch_mois<<"/"<<ch_annee<<endl;
}
void date::transformerdate()
{
    string ch_jour=to_string(jour);
    string ch_mois=to_string(mois);
    string ch_annee=to_string(annee);
    if(jour>9){
        if(mois>9){
            afficherdate();
        }
        else{
            cout<<"la date est : "<<ch_jour<<"/"<<"0"+ch_mois<<"/"<<ch_annee<<endl;
        }
    }
    else{
        if(mois>9){
            cout<<"la date est : "<<"0"+ch_jour<<"/"<<ch_mois<<"/"<<ch_annee<<endl;
        }
        else{
            cout<<"la date est : "<<"0"+ch_jour<<"/"<<"0"+ch_mois<<"/"<<ch_annee<<endl;
        }
    }

}
date::date(int j=1 ,int m=1 ,int a=2010)
{
    jour=j;
    mois=m;
    annee=a;
}

int main()
{
    date d(28,2,2011);

    d.afficherdate();
    d.transformerdate();




    return 0;
}
