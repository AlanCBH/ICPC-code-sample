#include <iostream>
#include <math.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

struct point
{
	double x,y;
	point(double xx=0,double yy=0)
	{
		x=xx;
		y=yy;
	}
};

double distance(point a,point b) {
	return sqrt( pow((a.x-b.x),2) + pow((a.y-b.y),2) );
}

bool check_not_120(int ax,int ay,int bx,int by,int cx,int cy) {
	double a = sqrt( pow((bx-cx),2) + pow((by-cy),2) );
	double b = sqrt( pow((ax-cx),2) + pow((ay-cy),2) );
	double c = sqrt( pow((bx-ax),2) + pow((by-ay),2) );
	if (a*a + b*b + a*b<= c*c ) {
		cout << cx << " "<<cy << endl;
		return false;
	} else if (a*a + c*c + a*c <= b*b ) {
		cout << bx << " " << by << endl;
		return false;
	} else if (c*c + b*b + c*b<= a*a) {
		cout << ax << " " << ay << endl;
		return false;	
	} else {
		return true;
	}
	
}
point get_outer_point(point pa,point pb,point pc) {
	
	double a = distance(pb,pc);
	double b = distance(pa,pc);
	double c = distance(pb,pa);


	double ka_y_1 = (pa.x-pb.x)/c;
	double ka_x_1 = -(pa.y-pb.y)/c;

	double ka_y_2 = -ka_y_1;
	double ka_x_2 = -ka_x_1;

	point mid = point((pa.x+pb.x)/2, (pa.y+pb.y)/2);
	point out_1 = point (mid.x + sqrt(3)/2*c*ka_x_1,mid.y + sqrt(3)/2*c*ka_y_1);
	point out_2 = point (mid.x + sqrt(3)/2*c*ka_x_2,mid.y + sqrt(3)/2*c*ka_y_2);
	
	double dist1 = distance(out_1,pc);
	double dist2 = distance(out_2,pc);

	if (dist1 > dist2) {
		return out_1;
	} else {
		return out_2;
	}
	//double new_ax = mid_ax + sqrt(3)/2*a*
	//double new_ay = 

}

int main ()
{
	int ax,ay,bx,by,cx,cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	point pa = point(ax,ay);
	point pb = point(bx,by);
	point pc = point(cx,cy);
	double a = distance(pb,pc);
	double b = distance(pa,pc);
	double c = distance(pa,pb);
	if ( check_not_120(ax,ay,bx,by,cx,cy) ) {
		point out_c = get_outer_point(pa,pb,pc);
		point out_a = get_outer_point(pc,pb,pa);
		//cout << out_c.x << " " << out_c.y << endl; 
		//cout << out_a.x << " " << out_a.y << endl; 
		double kc=(out_c.y-pc.y)/(out_c.x-pc.x);
		double ka=(out_a.y-pa.y)/(out_a.x-pa.x);
		
		double res_x=(kc*out_c.x- ka*out_a.x+out_a.y-out_c.y)/(kc-ka);
		
		double res_y=out_c.y+(res_x-out_c.x)*kc;
		
		cout <<fixed<<setprecision(9)<<res_x << " " <<res_y << endl;		

	}

  

  return 0;
}