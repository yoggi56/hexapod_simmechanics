classdef prms
    %CONTROLTABLE Summary of this class goes here
    %   Detailed explanation goes here
    
    properties(Constant)
        motor1 = 18;
        motor2 = 6;
        motor3 = 11;
        %leg parameters (cm, kg)
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
        %CoM stays in center of body. In axis Z too!

        %coordinates
        %leg1
        l1x = 15.78;
        l1y = 11.78;
        l1z = -14.9;

        %step
        stX = 4;
        stY = 0;
        stZ = 2;
        Ts = 2;

        
        g = 9.81;
        %engine parameters
%         Ka = 12;
%         L = 0.0006;%Ãí
%         R = 1.4;%Îì
%         Km = 4.375;%ôóíò-ñèëà*äþéì/À
%         n = 254;
%         JM = 0.00844;
%         JL = 1;
%         CM = 0.00013;
%         CL = 0.5;
%         Kb = 0.00867;
%         Ke = 1;
% 
%         J = JM + JL/n^2;
%         C = CM + CL/n^2;
    end
    
    methods
    end
    
end