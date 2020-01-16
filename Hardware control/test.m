while 1
    q1real = double(o.readAngle(servo1Id));
    q2real = double(o.readAngle(servo2Id));
    q3real = double(o.readAngle(servo3Id));
    [xreal, yreal, zreal] = fkine(q1real, q2real, q3real);
    
    set_param('Leg_mech/Constant7', 'Value', num2str(q1real));
    set_param('Leg_mech/Constant8', 'Value', num2str(q2real));
    set_param('Leg_mech/Constant9', 'Value', num2str(q3real));
    set_param('Leg_mech/Constant4', 'Value', num2str(xreal));
    set_param('Leg_mech/Constant5', 'Value', num2str(yreal));
    set_param('Leg_mech/Constant6', 'Value', num2str(zreal));
end