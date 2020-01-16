%init
%clear all
servo1Id = 9;
servo2Id = 6;
servo3Id = 11;

h = 2-12.7;
PEP = [16.806; 14.806; -12.7];
AEP = [20.806; 14.806; -12.7];
phase = 0;
T = 1;
t = 0;

o  = MyDynamixel();
o.portNum = 20;
o.baudNum = 1;
o.init()
o.addDevice(servo1Id);
o.addDevice(servo2Id);
o.addDevice(servo3Id);

o.setSpeed('id',servo1Id,'RPM',114);
o.setSpeed('id',servo2Id,'RPM',114);
o.setSpeed('id',servo3Id,'RPM',114);

% rt = timer;
% rt.TimerFcn = @[q1, q2, q3] = ikine(5,5,5);
% rt.Period = 0.001;
% rt.TasksToExecute = inf;
% rt.ExecutionMode = 'fixedSoacing';
% start(rt)

x = 0;
y = 0;
z = 0;
q1real = 0;
q2real = 0;
q3real = 0;
xreal = 0;
yreal = 0;
zreal = 0;
xrealMas = 0;
yrealMas = 0;
zrealMas = 0;
time = 0;
i = 1;
k = 1;
q1sm = 0;
q2sm = 0;
q3sm = 0;

[q1ref, q2ref, q3ref] = ikine(18.806,14.806,-12.7);
q1ref = q1ref*180/pi;
q2ref = q2ref*180/pi;
q3ref = q3ref*180/pi;
q1ref = q1ref + 150;
q2ref = 150 - q2ref;
q3ref = 150 - q3ref;
o.writeAngle('id',servo1Id,'deg',q1ref);
o.writeAngle('id',servo2Id,'deg',q2ref);
o.writeAngle('id',servo3Id,'deg',q3ref);
pause(1);
j = 1;

while 1
    %     q1real = 0;
    %     q2real = 0;
    %     q3real = 0;
    %     xreal = 0;
    %     yreal = 0;
    %     zreal = 0;
    %     xrealMas = 0;
    %     yrealMas = 0;
    %zrealMas = 0;
    %time = 0;
    %i = 1;
    k = k + 1;
    %% траекторный генератор-------------
    %фаза переноса
    if (x(k-1) ~= AEP(1)) && (phase == 0)
        t = [t t(i)+0.01];
        i = i + 1;
        x = [x funcX(AEP, PEP, T, phase, x(k-1), t(i))];
        y = [y funcY(AEP, PEP, T, phase, y(k-1), t(i))];
        z = [z funcZ(AEP, PEP, T, phase, z(k-1), t(i), h)];
    else
        phase = 2;
    end
    %фаза опоры
    if (x(k-1) ~= PEP(1))
        t = [t t(i) + 0.01];
        i = i + 1;
        x = [x funcX(AEP, PEP, T, phase, x(i-1), t(i)-t0)];
        y = [y funcY(AEP, PEP, T, phase, y(i-1), t(i)-t0)];
        z = [z funcZ(AEP, PEP, T, phase, z(i-1), t(i), h)];
    end
    %раскоментить, когда будет выключатель
    %фаза опускания
    %     if (x(k-1) ~= PEP(1)) && (phase == 1)
    %         t = [t t(j) + 0.01];
    %         j = j + 1;
    %         x = [x funcX(AEP, PEP, T, phase, x(k-1), t(j))];
    %         y = [y funcY(AEP, PEP, T, phase, y(k-1), t(j))];
    %         z = [z funcZ(AEP, PEP, T, phase, z(k-1), t(j), h)];
    %     else
    %         phase = 0;
    %         %t = 0;
    %         %i = 1;
    %     end
    if (phase == 0)
        j = 1;
    end
    %     if (phase == 1)
    %         i = 1;
    %     end
    %% -------------------------------------------
    [q1ref, q2ref, q3ref] = ikine(x(k),y(k),z(k));
    [xTest, yTest, zTest] = fkine(q1ref, q2ref, q3ref);
    q1sm = q1ref;
    q2sm = q2ref;
    q3sm = q3ref;
    q1ref = q1ref*180/pi;
    q2ref = q2ref*180/pi;
    q3ref = q3ref*180/pi;
    if (q1ref > 60) || (q1ref < -60) || (q2ref > 90) || (q2ref < -90) || (q3ref > 150) || (q3ref < -150)
        disp('Solved angles too big');
    else
        if (abs(xTest-x(k)) > 0.2) && (abs(yTest-y(k)) > 0.2) && (abs(yTest-y(k)) > 0.2)
            disp('Your position too far');
        else
            q1ref = q1ref + 150;
            q2ref = 150 - q2ref;
            q3ref = 150 - q3ref;
            o.writeAngle('id',servo1Id,'deg',q1ref);
            o.writeAngle('id',servo2Id,'deg',q2ref);
            o.writeAngle('id',servo3Id,'deg',q3ref);
            
            %             set_param('Leg_mech/Constant4', 'Value', num2str(x(k)));
            %             set_param('Leg_mech/Constant5', 'Value', num2str(y(k)));
            %             set_param('Leg_mech/Constant6', 'Value', num2str(z(k)));
            %
            %             set_param('Leg_mech/Gain', 'Gain', num2str(q1sm));
            %             set_param('Leg_mech/Gain1', 'Gain', num2str(q2sm));
            %             set_param('Leg_mech/Gain2', 'Gain', num2str(q3sm));
            
            %             tic
            %             while toc < 0.9
            %                 q1real = [q1real, double(o.readAngle(servo1Id))];
            %                 q2real = [q2real, double(o.readAngle(servo2Id))];
            %                 q3real = [q3real, double(o.readAngle(servo3Id))];
            %                 time = [time, toc];
            %             end
            %             q1real(~q1real) = [];
            %             q2real(~q2real) = [];
            %             q3real(~q3real) = [];
            %
            %             time(~time) = [];
            %             if size(q1real, 2) ~= size(time, 2)
            %                 q1real(size(q1real, 2)) = [];
            %             end
            %             if size(q2real, 2) ~= size(time, 2)
            %                 q2real(size(q2real, 2)) = [];
            %             end
            %             if size(q3real, 2) ~= size(time, 2)
            %                 q3real(size(q3real, 2)) = [];
            %             end
            %
            %             q1real = q1real-150;
            %             q2real = 150 - q2real;
            %             q3real = 150 - q3real;
            %
            % %             figure(1);
            % %             plot(time, q1real);
            % %             figure(2);
            % %             plot(time, q2real);
            % %             figure(3);
            % %             plot(time, q3real);
            %
            %
            %             q1real = q1real*pi/180;
            %             q2real = q2real*pi/180;
            %             q3real = q3real*pi/180;
            %
            %             xrealMas(~xrealMas) = [];
            %             yrealMas(~yrealMas) = [];
            %             zrealMas(~zrealMas) = [];
            %             while i < size(q1real, 2)+1
            %                 [xreal yreal zreal] = fkine(q1real(i), q2real(i), q3real(i));
            %                 xrealMas = [xrealMas, xreal];
            %                 yrealMas = [yrealMas, yreal];
            %                 zrealMas = [zrealMas, zreal];
            %                 i = i + 1;
            %             end
            %             figure(4);
            %             plot(time, xrealMas);
            %             figure(5);
            %             plot(time, yrealMas)
            %             figure(6);
            %             plot(time, zrealMas)
        end
    end
    pause(0.01);
    
end
