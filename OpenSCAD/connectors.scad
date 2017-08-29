include <28BYJ-48-Stepper-Motor.scad>;
//$fn = 360;
$fn = 36;
$height = 5;
$margin = 2.5;

$hole_radius = 2.5;
$hole_thickness = 3;

$body_radius = 14;


module motor_head(){
       intersection(){
           cylinder($height,$hole_radius,$hole_radius);
           cube([$hole_thickness,$hole_radius*2,$height*2],true);
       }
}

module motor_body(){
    rotate([0,0,-90]) stepper28BYJ();
}

module connector_head_to_head($distance = 50){
    difference(){
        hull(){
            cylinder($height,$hole_radius + $margin,$hole_radius + $margin);
            translate([$distance,0,0]) 
                cylinder($height,$hole_radius + $margin,$hole_radius + $margin);
        }
        motor_head();
        translate([$distance,0,0]) motor_head();
    }
}

module connector_head_to_body($distance = 50,$rotate_motor = 0){
    difference(){
        hull(){
            cylinder($height,$hole_radius + $margin,$hole_radius + $margin);
            translate([$distance,0,0])
                cylinder($height,$body_radius + $margin,$body_radius + $margin);  
        }
        motor_head();
        translate([$distance,0,0]) rotate([0,0,$rotate_motor]) motor_body();
    }
}


 connector_head_to_head(70);

translate([0,-30,0]) connector_head_to_body(70);
translate([0,30,0]) connector_head_to_body(70,180);

//translate([0,-40,0]) motor_body();