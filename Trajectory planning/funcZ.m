function [zNew] = funcZ(AEP, PEP, T, phase, z, t, h)

    switch phase
        case 0 %фаза переноса
            if t <= T/6
                a0 = PEP(3);
                a1 = 0;
                a2 = (3/((T/6)^2))*(h - PEP(3));
                a3 = (-2/((T/6)^3))*(h - PEP(3));
                zNew = round(a0 + a1*t + a2*(t^2) + a3*(t^3), 2);
            elseif (t > T/6) && (t < 2*T/6)
                zNew = h;
            else 
                t = t - 2*T/6;
                a0 = h;
                a1 = 0;
                a2 = (3/((T/6)^2))*(AEP(3) - h);
                a3 = (-2/((T/6)^3))*(AEP(3) - h);
                zNew = round(a0 + a1*t + a2*(t^2) + a3*(t^3), 2);
            end
        case 1 %фаза опускания
            zNew = z - 0.05;
        case 2 %фаза опоры
            zNew = z;
    end
end