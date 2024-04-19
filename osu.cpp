#include <random>
#include <iostream>
#include <Grapic.h>
#include <cstdlib>
#include <time.h>
/*
j'ai remplace l'image par une image qui est deja presnt dans grapic par defaut
ajout :
-fix de la vitesse d'apparition des cibles

-creation d'un menu de fin affichant les stats de la derniere partie joué

-


liste de chose a faire :
creation fonction toggle pour souris
ajout des differente diffuclté
ajout cible mouvante
*/
using namespace grapic;

const int DIM_X= 1000;
const int DIM_Y= 700;



bool isMouseInCircle(int mx, int my, int cx, int cy, int r) {
    // Calcul de la distance entre la souris et le centre du cercle
    int distance = std::sqrt(std::pow(mx - cx, 2) + std::pow(my - cy, 2));

    // Vérifie si la distance est inférieure ou égale au rayon du cercle
    return distance <= r;
}

//   1 /1 + e^-xx

float precisionPointCercle(int mx,int my, int cx, int cy, int r)
{
    int distance = std::sqrt(std::pow(mx - cx, 2) + std::pow(my - cy, 2));
    return std::fabs(distance - r);
}
struct data
{
    int x,y;
    Image im;


};


void menu_principale(int &play, int &level)
{
    int x,y;
    data d;

    mousePos(x,y);
    winClear();

    color(255,255,255);
    print(DIM_X/3 -20, DIM_Y/1.75 + 150, "AIM LABORATORY");
    //menu
    rectangleFill(300,500, 650, 430);
    rectangleFill(300,400,650,330);
    rectangleFill(300,300,650,230);

    //level
    rectangleFill(300,200,390,130);//1
    rectangleFill(430,200,520,130);//2
    rectangleFill(560,200,650,130);//3


    color(0,0,0);
    print(950/2 - 25, (400 + 330)/2 -10, "Quitter");
    print(950/2 - 25, (500+430)/2 -10, "Play");
    print(950/2 - 25, (300+230)/2 -10, "Difficulté : ");
    print(950/1.72 , (300+230)/2 -10, level);
    print(345, (130+200)/2, "1");
    print(470, (130+200)/2, "2");
    print(605, (130+200)/2, "3");

    d.im = image("data/projet/osu.png");
    image_draw(d.im,DIM_X/2, DIM_Y/1.325, 128, 128, 0);


    if ((x > 300 && x < 650 && y > 430 && y <500))
        {
            color(255,0,0);
            rectangleFill(300,500, 650, 430);
            color(0,0,0);
            print(950/2 - 25, (500+430)/2 -10, "Play");
            if (isMousePressed(SDL_BUTTON_LEFT))  delay(300), play = 1;
        }

    if (x > 300 && x < 650 && y > 330 && y < 400)
    {
        color(255,0,0);
        rectangleFill(300,400,650,330);
        color(0,0,0);
        print(950/2 - 25, (400 + 330)/2 -10, "Quitter");
        if (isMousePressed(SDL_BUTTON_LEFT)) play =3;

    }
    //1
    if ((x > 300 && x < 390 && y > 130 && y <200))
        {
            color(255,0,0);
            rectangleFill(300,200,390,130);//1
            color(0,0,0);
            print(345, (130+200)/2, "1");
            if (isMousePressed(SDL_BUTTON_LEFT)) level=1;
        }
    //2
    if ((x > 430 && x < 520 && y > 130 && y <200))
        {
            color(255,0,0);
            rectangleFill(430,200,520,130);//2
            color(0,0,0);
            print(470, (130+200)/2, "2");
            if (isMousePressed(SDL_BUTTON_LEFT)) level = 2;
        }
    //3
    if ((x > 560 && x < 650 && y > 130 && y <200))
        {
            color(255,0,0);
            rectangleFill(560,200,650,130);//3
            color(0,0,0);
            print(605, (130+200)/2, "3");
            if (isMousePressed(SDL_BUTTON_LEFT)) level = 3;
        }
}



void menu_fin(int &play,int &score, int &compteur,float &temps_total, int level, float &accurate)
 {
    int x,y;
    data d;
    mousePos(x,y);
    winClear();

    color(255,255,255);
    print(DIM_X/3 -20, DIM_Y/1.75 + 150, "AIM LABORATORY");

    rectangleFill(300,500, 650, 430);
    rectangleFill(300,400,650,330);

    color(0,204,255);
    rectangleFill(0,0,50,50);
    rectangleFill(300,300,650,230);
    rectangleFill(300,200,650,130);
    rectangleFill(300,100,650,030);

    color(0,0,0);
    print (20,17,level);
    print(950/2 - 25, (400 + 330)/2 -10, "Quitter");
    print(950/2 - 25, (500+430)/2 -10, "Menu");
    print(950/2 -75, (100+30)/2 -10, "Temps = ");
    print(950/2 +15, (100+30)/2 -10, temps_total);


    print(950/2 - 50, (300+230)/2-10, "Last score = ");
    print(950/1.75 ,(300+230)/2-10, score);
    print(950/1.75 + 35 ,(300+230)/2-10, "/");
    print(950/1.75 + 45 ,(300+230)/2-10, compteur-1);
    print(950/2 - 50, (200+130)/2-10, "Précision = ");
    print(950/1.75 ,(200+130)/2-10, accurate);


    if ((x > 300 && x < 650 && y > 430 && y <500))
        {
            color(255,0,0);
            rectangleFill(300,500, 650, 430);
            color(0,0,0);
            print(950/2 - 25, (500+430)/2 -10, "Menu");
            if (isMousePressed(SDL_BUTTON_LEFT))
            {
                score =0;
                compteur=0;
                play = 0;
                delay(300);
            }
        }

    if (x > 300 && x < 650 && y > 330 && y < 400)
    {
        color(255,0,0);
        rectangleFill(300,400,650,330);
        color(0,0,0);
        print(950/2 - 23, (400 + 330)/2 -10, "Quitter");
        if (isMousePressed(SDL_BUTTON_LEFT)) play = 3;

    }
    d.im = image("data/projet/osu.png");
    image_draw(d.im,DIM_X/2, DIM_Y/1.325, 128, 128, 0);

}


void game(int & compteur, int & score, bool &spawn, int &level, float & precision, int timer_level)
{
    int x,y,xc,yc,r,fx,fy, move_target_x, move_target_y;
    float tmpx, tmpy;
    color(255,105,180);
    if(level == 1)r = 20;
    if(level == 2)r = 15;
    if(level == 3)r = 10;
    float time;
    float temps_cible;
    if (compteur == 0) spawn = true;
    if(spawn)
    {
        xc = rand() % (1001-r);
        yc = rand() % (701-r);
        tmpx=xc;
        tmpy= yc;
        circleFill(xc,yc,r);
        compteur += 1;
        if (level == 3)
        {
            move_target_x = rand()%5;
            move_target_y = rand()%5;

        }
        time = elapsedTime();
        std::cout<<"compteur"<<compteur<<std::endl;
        spawn = false;
    }
    temps_cible = elapsedTime() - time;
    if(!spawn)
    {
        if (level == 3)
        {

            std::cout<<"update"<<std::endl;
            if ((tmpx > r && tmpy > r) || tmpx < (DIM_X -r && tmpy < DIM_Y - r))
            {
                if (move_target_x == 0 && move_target_y == 0 )tmpx += 0.045897, tmpy += 0.045897;
                if ((move_target_x !=0) && move_target_y == 0)tmpy += 0.045897;
                if (move_target_x ==0 && move_target_y !=0 ) tmpx += 0.045897;

                if (move_target_x == 1 && move_target_y == 1 )tmpx -= 0.045897, tmpy -= 0.045897;
                if ((move_target_x !=1) && move_target_y == 1)tmpy -= 0.045897;
                if (move_target_x ==1 && move_target_y !=0 ) tmpx -= 0.045897;



            }
            circleFill(tmpx,tmpy,r);
        }else
        {
            circleFill(tmpx,tmpy,r);
        }

    }
    mousePos(x,y);

    if (isMouseInCircle(x,y,tmpx,tmpy,r) && isMousePressed(SDL_BUTTON_LEFT))
    {
        score += 1;
        std::cout<<"score"<<score<<std::endl;
        precision += precisionPointCercle(x,y,tmpx,tmpy,r);
        //precision = precision + precisionPointCercle(x,y,tmpx,tmpy,r);
        spawn = true;
        std::cout << "HERE" << spawn<< std::endl;

    }
    //std::cout << isMousePressed(SDL_BUTTON_LEFT) << std::endl;
    //std::cout<<"temps de target"<<temps_cible<<std::endl;
    if (temps_cible > timer_level)
    {
        spawn = true;
        precision += 0;
        std::cout<<"cible rate a cause de colepo0509"<<std::endl;
    }
}


int main(int , char **)
{
    //setKeyRepeatMode(true);
    int score = 0;
    int compteur = 0;
    int x,y;
    int play = 0;
    bool view = true;
    srand(time(NULL));
    bool stop=false;
    bool finished =false;
    winInit("AIM_LABORATORY", DIM_X,DIM_Y);
    backgroundColor( 0, 0, 0 );
    int time;
    bool spawn= false;
    float start_time;
    bool start = true;
    float temps_total;
    int level= 1;
    float accurate=0.f;
    while (!stop)
    {

            if (play == 0 )
            {
                menu_principale(play, level);
            }

            if (play== 1)
            {
                winClear();

                if (compteur <=10 ) //100/10 pour tester
                {
                    if(start) start_time = elapsedTime(), start = false;
                    if (level == 1)game(compteur, score, spawn, level, accurate, 3.1);
                    if (level == 2)game(compteur, score, spawn, level, accurate, 2.5);
                    if (level == 3)game(compteur, score, spawn, level, accurate, 2);

                }else
                    {
                        temps_total = elapsedTime() - start_time;
                        start = true;
                        if (level ==1) accurate = accurate*100/(compteur*20);
                        if (level ==2) accurate = accurate*100/(compteur*15);
                        if (level ==3 ) accurate = accurate*100/(compteur*10);

                        play =2;
                        delay(300);

                    }
            }
            if (play ==2)
            {
                menu_fin(play, score, compteur, temps_total, level, accurate);
            }

            if(play == 3)
            {
                winQuit();
            }

        stop = winDisplay();
    }
    return 0;
}
