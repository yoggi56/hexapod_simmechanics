q1 = 15*pi/180;
q2 = 35*pi/180;
q3 = 10*pi/180;

x = bL/2 + cos(pi/4+q1)*(L1 + L2*cos(q2) + L3*cos(q2 - pi/2 - q3))
y = bWs/2 + sin(pi/4+q1)*(L1 + L2*cos(q2) + L3*cos(q2 - pi/2 - q3))
z = L2*sin(q2) + L3*sin(q2 - pi/2 - q3)