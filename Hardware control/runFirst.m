clear all

g = 9.81;
%engine parameters
Ka = 12;
L = 0.0006;%Ãí
R = 1.4;%Îì
Km = 4.375;%ôóíò-ñèëà*äþéì/À
n = 254;
JM = 0.00844;
JL = 1;
CM = 0.00013;
CL = 0.5;
Kb = 0.00867;
Ke = 1;

J = JM + JL/n^2;
C = CM + CL/n^2;

%legs parameters (cm, kg)
L1 = 3.4;%3.53;
L2 = 8.7;%5.7;
L3 = 12.7;%12.6;
d1 = 0;%-2.3;
d2 = 0;%-4.158;
m1 = 0.158; %mass of the first link
m2 = 0.034; %mass of the second link
m3 = 0.102; %mass of the third link

%body parameters (cm, kg, grad)
bL = 20.5;
bWs = 12.5;
bWb = 14.5;
bH = 4;
%bodyHeight = 1;
bM = 0.835;
L1R = 45;
L2R = 0;
L3R = -45;
L4R = -45;
L5R = 0;
L6R = 45;

%bH = 18.5;
%bLb = 12.5;
%bLs = 10.5;

%surface parameters
surfX = 4;
surfY = 1;
surfZ = 0.01;

%coordinates
%leg1
l1x = 15.78;
l1y = 11.78;
l1z = -14.9;
%leg2
l2x = 0;
l2y = 15.48;
l2z = -14.9;
%leg3
l3x = -15.78;
l3y = 11.78;
l3z = -14.9;
%leg4
l4x = 15.78;
l4y = -11.78;
l4z = -14.9;
%leg5
l5x = 0;
l5y = -15.48;
l5z = -14.9;
%leg6
l6x = -15.78;
l6y = -11.78;
l6z = -14.9;
%step
stX = 4;
stY = 0;
stZ = 2;
Ts = 2;

%contact coefficients
Mmr = bM + 6*(m1 + m2 + m3);%Mass of mobile robot
Mleg = 6*(m1 + m2 + m3);%mass of each leg
Lleg = L1 + L2 + L3;%length of each leg
wmax = 7.1574;%maximum angular velocity
emax = 0.1;%max interpenetration of the leg to ground
xd = 0.1;%max displacement
zeta = 1;%damped coeff (1 - critically damped)
Fext = Mmr*g;
k = Fext/emax;%spring constant
c1 = 2*zeta*sqrt(Mmr*k);%damped constant
vmax = wmax*Lleg;
c2 = (vmax*Mleg)/xd;%friction constant
