
clc
clear
dynamixel_id = 9;
o  = MyDynamixel(dynamixel_id);
% o.viewSupportFcn();
o.portNum = 20;
o.baudNum = 1;
o.init()
o.addDevice(9);
%o.addDevice(16);
%% Set Speed
o.setSpeed('id',9,'RPM',20);
%o.setSpeed('id',16,'RPM',10);
% o.setSpeed('id',5,'maxSpeed');
% o.setSpeed('id',5,'maxSpeedNoControl');

%% Write Command
while 1
    k = input('angle=: ');
    if strcmp(k,'q')
        break;
    end
    o.writeAngle('id',9,'deg',k);
    %o.writeAngle('id',16,'deg',k);
end


% o.writeAngle('id',5,'rad',pi);
% o.writeAngle('index',1,'deg',100);
% o.writeAngle('index',1,'rad',pi);
% o.Exit();