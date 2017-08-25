$height = 5;
$outer_radius = 5;
$distance = 50;

$hole_radius = 2.5;
$hole_thickness = 3;


difference(){
    hull(){
        cylinder($height,$outer_radius,$outer_radius);
        translate([$distance,0,0]) cylinder($height,$outer_radius,$outer_radius);
    }
}