classdef MyDynamixel < handle
    %MYDYNAMIXEL Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        portNum;
        baudNum;
        libName = 'dynamixel'
        Devices = struct('id',[],'offset',0,'x',0,'xMin',0,'xMax',deg2rad(300),'name','motor1','index',1,'status','active','speed',10,...
            'maxSpeed',114);
        Instruction;
        numDevices = 0;
        
    end
    
    methods
        function MD = MyDynamixel(port,baud)
            if (nargin == 2)
                MD.portNum = port;
                MD.baudNum = baud;
                res = calllib(MD.libName, 'dxl_initialize',MD.portNum, MD.baudNum);
                if res == 0
                    fprintf('Cannot init dynamixel \n');
                end
            else
                fprintf('Serial port does not configure \n')
            end
            MD.Instruction.PING = hex2dec('01');
            MD.Instruction.READ_DATA = hex2dec('02');
            MD.Instruction.WRITE_DATA = hex2dec('03');
            MD.Instruction.REG_WRITE = hex2dec('04');
            MD.Instruction.ACTION = hex2dec('05');
            MD.Instruction.RESET = hex2dec('06');
            MD.Instruction.SYNC_WRITE = hex2dec('83');
            loadlibrary('dynamixel', 'dynamixel.h')
        end
        function Exit(MD)
            calllib('dynamixel','dxl_terminate');
            unloadlibrary(MD.libName);
        end
        function init(MD,port,baud)
            if (nargin ==3)
                MD.portNum = port;
                MD.baudNum = baud;
                res = calllib(MD.libName, 'dxl_initialize',MD.portNum, MD.baudNum);
                if res == 0
                    fprintf('Cannot init dynamixel \n');
                end
            else
                res = calllib(MD.libName, 'dxl_initialize',MD.portNum, MD.baudNum);
                if res == 0
                    fprintf('Cannot init dynamixel \n');
                end
            end
            
        end
        function viewSupportFcn(MD)
           
            libfunctions(MD.libName);
        end
        function addDevice(MD,id)
            MD.numDevices = MD.numDevices + 1;
            MD.Devices(MD.numDevices).id = id;
            MD.Devices(MD.numDevices).status = 'active';
            MD.Devices(MD.numDevices).index = MD.numDevices;
            MD.Devices(MD.numDevices).offset = 0;
            MD.Devices(MD.numDevices).xMin = 0;
            MD.Devices(MD.numDevices).xMax = deg2rad(300);
            MD.Devices(MD.numDevices).x = 0;
            MD.Devices(MD.numDevices).name = 'noname';
            MD.Devices(MD.numDevices).speed = 10;
            MD.Devices(MD.numDevices).maxSpeed = 114;
        end
        function removeDevice(MD,id)
            for i = 1: MD.numDevices
                if (id == MD.Devices(i).id)
                    MD.Devices(i).status = 'inactive';
                end
            end
        end        
        function writeAngle(MD,varargin)
            n = length(varargin);
            i = 1;
            if (n >3)
                while(i < n)
                    prop = varargin{i};
                    val = varargin{i+1};
                    switch prop
                        case 'id'
                            for j = 1: length(MD.Devices)
                                if MD.Devices(j).id == val
                                    ind = j;
                                end
                            end
                        case 'index'
                            ind = val;
                        case 'deg'
                            val = deg2rad(val);                                                                                                             
                            if val < MD.Devices(ind).xMin
                                val = MD.Devices(ind).xMin;
                            end
                            if val > MD.Devices(ind).xMax
                                val = MD.Devices(ind).xMax;
                            end
                            MD.Devices(ind).x = val;
                            dat = val + MD.Devices(ind).offset;    % rad                 
                            dat = uint16(rad2deg(dat)*1023/300);
                        case 'rad'
                            
                            if val < MD.Devices(ind).xMin
                                val = MD.Devices(ind).xMin;
                            end
                            if val > MD.Devices(ind).xMax
                                val = MD.Devices(ind).xMax;
                            end
                            MD.Devices(ind).x = val;
                            %prepare real data for dynamixel
                            dat = rad2deg(val + MD.Devices(ind).offset); % deg
                            dat = uint16(dat*1023/300);
                    end                      
                    i = i+2;
                end
                calllib('dynamixel','dxl_write_word',MD.Devices(ind).id,ControlTable.GoalPos_L,dat); 
            end
          
        end
        function setSpeed(MD,varargin)
            n = length(varargin);
            i = 1;
            if (n >=3)
                while(i < n)
                    prop = varargin{i};
                    val = varargin{i+1};
                    switch prop
                        case 'id'
                            for j = 1: length(MD.Devices)
                                if MD.Devices(j).id == val
                                    ind = j;
                                end
                            end
                        case 'index'
                            ind = val;
                        case 'RPM'                                                                                                             
                            if val < 1
                                val = 1;
                            end
                            if val > MD.Devices(ind).maxSpeed
                                val = MD.Devices(ind).maxSpeed;
                            end
                            MD.Devices(ind).speed = val;                
                            dat = uint16(val*1023/114);
                        case 'maxSpeed'
                            MD.Devices(ind).speed = 114;
                            dat = 1023;
                        case 'maxSpeedNoControl'
                            MD.Devices(ind).speed = 0;
                            dat = 0;
                    end                      
                    i = i+2;
                end
                calllib('dynamixel','dxl_write_word',MD.Devices(ind).id,ControlTable.MovingSpeed_L,dat); 
            end
        end
        
        function ledOn(MD)
            calllib(MD.libName,'dxl_write_byte',2,ControlTable.LED,1);
        end
        function ledOff(MD)
            calllib(MD.libName,'dxl_write_byte',2,ControlTable.LED,0);
        end
        
        %% My functions
        function [angle] = readAngle(MD, id)
            angle = int32(calllib(MD.libName,'dxl_read_word', id, ControlTable.PresentPos_L))*300/1023; 
        end
    end
end

