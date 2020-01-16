AEP = [4; 0; 0];
PEP = [-4; 0; 0];
T = 1;
h = 2;
t = 0;
x = 0;
y = 5;
z = 0;
i = 1;
k = 0;
tconst = 0;

% 1)включение
touched = true;
PEP = [0; 5; 0];
AEP = [4; 6; 0];
phase = 0;

t = [t t+0.01];
i = i + 1;
x = [x funcX(AEP, PEP, T, phase, x(1), t(i))];
y = [y funcY(AEP, PEP, T, phase, y(1), t(i))];
z = [z funcZ(AEP, PEP, T, phase, z(1), t(i), h)];
for k = 0:1:3
    disp(k);
    phase = 0;
    %фаза опоры
    while touched == true;
        t = [t t(i)+0.01];
        i = i + 1;
        x = [x funcX(AEP, PEP, T, phase, x(i-1), t(i))];
        y = [y funcY(AEP, PEP, T, phase, y(i-1), t(i))];
        z = [z funcZ(AEP, PEP, T, phase, z(i-1), t(i), h)];
        if x(i) >= 0.2
            touched = false;
        end
        x;
    end
    % фаза переноса
    disp(k);
    while (touched == false) && (x(i) ~= AEP(1))
        t = [t t(i) + 0.01];
        i = i + 1;
        x = [x funcX(AEP, PEP, T, phase, x(i-1), t(i))];
        y = [y funcY(AEP, PEP, T, phase, y(i-1), t(i))];
        z = [z funcZ(AEP, PEP, T, phase, z(i-1), t(i), h)];
        x(i);
    end

    %фаза опускания
    phase = 1;
    disp(k);
    while (touched == false) && (x(i) == AEP(1))
        if t(i) >= 0.6
            touched = true;
        end
        t = [t t(i) + 0.01];
        i = i + 1;
        x = [x funcX(AEP, PEP, T, phase, x(i-1), t(i))];
        y = [y funcY(AEP, PEP, T, phase, y(i-1), t(i))];
        z = [z funcZ(AEP, PEP, T, phase, z(i-1), t(i), h)];
    end
    disp(k);
    %фаза опоры
    phase = 2;
    PEP = double([-4; 5; 0]);
    t0 = t(i);
    while (x(i) ~= PEP(1))
        t = [t t(i) + 0.01];
        i = i + 1;
        x = [x funcX(AEP, PEP, T, phase, x(i-1), t(i)-t0)];
        y = [y funcY(AEP, PEP, T, phase, y(i-1), t(i)-t0)];
        z = [z funcZ(AEP, PEP, T, phase, z(i-1), t(i), h)];
    end
    disp(k);
    figure();
    plot(t, x);
    figure();
    plot(t, y);
    figure()
    plot(t, z);
    figure()
    plot(x,z)
    t = 0;
    x = PEP(1);
    y = PEP(2);
    z = z(i);
    i = 1;
end



