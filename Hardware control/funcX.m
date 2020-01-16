function [xNew] = funcX(AEP, PEP, T, phase, x, t)

    switch phase
        case 0 %фаза переноса
            a0 = PEP(1);
            a1 = 0;
            a2 = (3/((T/2)^2))*(AEP(1) - PEP(1));
            a3 = (-2/((T/2)^3))*(AEP(1) - PEP(1));
            xNew = round(a0 + a1*t + a2*(t^2) + a3*(t^3), 3);
        case 1 %фаза опускания
            xNew = x;
        case 2 %фаза опоры
            a0 = AEP(1);
            a1 = 2*(PEP(1) - AEP(1))/T;
            xNew = round(a0 + a1*t, 3);
    end
end