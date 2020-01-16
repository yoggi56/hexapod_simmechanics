function [q1, q2, q3] = ikine(x, y, z)
    xnew1 = (2^(1/2)/2)*(x + y - prms.bL/2 - prms.bWs/2);
    ynew1 = (2^(1/2)/2)*(-x + y + prms.bL/2 - prms.bWs/2);
    znew1 = z;

    q1 = atan2(ynew1, xnew1);

    xnew2 = cos(q1)*xnew1 + sin(q1)*ynew1 - prms.L1;
    ynew2 = -sin(q1)*xnew1 + cos(q1)*ynew1;
    znew2 = znew1;

    L4 = sqrt(znew2^2+xnew2^2);
    q2 = acos((prms.L2^2 + L4^2 - prms.L3^2)/(2*prms.L2*L4)) - atan2(abs(znew2), xnew2);
    q3 = pi - acos((prms.L2^2+prms.L3^2-L4^2)/(2*prms.L2*prms.L3));
    
    if z > 0 
        q2 = -q2;
        q3 = -q3;
    end
end