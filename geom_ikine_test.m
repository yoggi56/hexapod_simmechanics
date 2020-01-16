x = 16.0457;
y = 17.0205;
z = -8.0117;

xnew1 = (2^(1/2)/2)*(x + y - bL/2 - bWs/2);
ynew1 = (2^(1/2)/2)*(-x + y + bL/2 - bWs/2);
znew1 = z;

q1 = atan2(ynew1, xnew1);

xnew2 = cos(q1)*xnew1 + sin(q1)*ynew1 - L1;
ynew2 = -sin(q1)*xnew1 + cos(q1)*ynew1;
znew2 = znew1;

L4 = sqrt(znew2^2+xnew2^2);
q2 = acos((L2^2 + L4^2 - L3^2)/(2*L2*L4)) - atan2(abs(znew2), xnew2);
q3 = pi - acos((L2^2+L3^2-L4^2)/(2*L2*L3));

q1 = q1*180/pi
q2 = q2*180/pi
q3 = q3*180/pi