#include<graphics.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL); 
    
    int x,y;
    for(int i=0;i<=550;i++){
        //Platform
        line(20,380,580,380);
        //Leg movment
        if(i%2==0){
            line(25+i,380,35+i,340); //leftleg
            line(45+i,380,35+i,340);//right leg
            line(35+i,310,25+i,330);//left hand
            delay(20);
        }
        //hand movement
        else{
            line(35+i,380,35+i,340);
            // line(35+i,310,40+i,330);
            delay(20);
        }
        line(35+i,340,35+i,310);
        
        //head
        circle(35+i,300,10); 

        line(35+i,310,50+i,330);
        line(50+i,330,50+i,280); //umbrella stick
        line(15+i,280,85+i,280); //umbrella right
        arc(50+i,280,180,360,35); //umbrella body

        //create rain
        for(int a=0;a<=200;a++){
            A:
            x = (random())%600;
            y = (random())%350;
            //check if rain is inisde the body or not
            if(x>(15+i) and x<(85+i) and y>245 and y<345 ){
                goto A;
            }
            
            outtextxy(x,y,"|");
        }
        delay(40);
        cleardevice();
    }



    delay (2000);
	closegraph();

   	return 0;
}

