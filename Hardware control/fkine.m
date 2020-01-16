
function [x y z] = fkine(q1, q2, q3)
    x = prms.bL/2 + cos(pi/4+q1)*(prms.L1 + prms.L2*cos(q2) + prms.L3*cos(q2 - q3))
    y = prms.bWs/2 + sin(pi/4+q1)*(prms.L1 + prms.L2*cos(q2) + prms.L3*cos(q2 - q3))
    z = prms.L2*sin(q2) + prms.L3*sin(q2 - q3)
end