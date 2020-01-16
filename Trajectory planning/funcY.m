function [yNew] = funcY(AEP, PEP, T, phase, y, t)

    switch phase
        case 0 %���� ��������
            a0 = PEP(2);
            a1 = 0;
            a2 = (3/((T/2)^2))*(AEP(2) - PEP(2));
            a3 = (-2/((T/2)^3))*(AEP(2) - PEP(2));
            yNew = round(a0 + a1*t + a2*(t^2) + a3*(t^3), 2);
        case 1 %���� ���������
            yNew = y;
        case 2 %���� �����
            a0 = AEP(2);
            a1 = 2*(PEP(2) - AEP(2))/T;
            yNew = round(a0 + a1*t, 2);
    end
end