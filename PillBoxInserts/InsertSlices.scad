$fn = 100; // Increase for smoother curves
edge_length = 30; // Edge length in mm
thickness = 1; // Thickness of the slice in mm
angle = asin(1.5 / (edge_length / 2)) * 2 * 180 / PI; // Calculate angle to make the slice 3 cm long
cylinder_height = thickness * 4; // Height of the cylinder
cylinder_diameter = thickness; // Diameter of the cylinder
cube_height = thickness * 5; // Height is twice the pizza slice thickness
cube_length = edge_length * 2; // Length from -1 to 3 along the X-axis
cube_width = edge_length * 2; // Width from -3 to 3 along the Y-axis


// Pizza slice footprint, adjusted for new orientation
module pizzaSliceFootprint() {
    rotate([0, 0, -angle/2]) // Rotate so edges sandwich the Y-axis
    polygon(points=[[0, 0], [edge_length/2, 0], [edge_length/2*cos(angle), edge_length/2*sin(angle)], [0, 0]]);
}

// Clipping cube to flatten the top 10% of the pizza slice
module clippingCube() {
    cube_height = thickness * 5; // Height is twice the pizza slice thickness
    cube_length = 4; // Length from -1 to 3 along the X-axis
    cube_width = 6; // Width from -3 to 3 along the Y-axis
    translate([-1, -3, -1]) // Position the cube starting at -1,-3
    color("blue")
    cube([cube_length, cube_width, cube_height]);
}

// Extruding the footprint to create the slice with clipping effect
module pizzaSliceWithClipping() {
    difference() {
        linear_extrude(height = thickness) {
            pizzaSliceFootprint();
        }
        clippingCube();
    }
}

// Adding the cylinder on the right edge of the crust as a handle
module cylinderOnCrust() {
    
    // Translate the cylinder to the correct position on the right side
    translate([(edge_length/2) - cylinder_diameter * 4, 0, 0]) // Move the cylinder to the right side
    // Rotate the cylinder 45 degrees around the Z-axis at the intersection point
    rotate([0, 45, 0])
    // Create the cylinder
    cylinder(h = cylinder_height, d = cylinder_diameter, $fn = $fn);
}

// Clipping cube to flatten the top 10% of the pizza slice
module clippingCylinder(z_offset) {
    translate([-edge_length, -edge_length, z_offset]) // Position the cube starting at -1,-3
    color("blue")
    cube([cube_length, cube_width, cube_height]);
}


// Extruding the footprint to create the slice with clipping effect
module cylinderWithClipping() {
    difference() {
        cylinderOnCrust();
        clippingCylinder(thickness * 2);
        clippingCylinder(-cube_height);
    }
}

module finalSlice() {
// Render the pizza slice with the clipping effect
pizzaSliceWithClipping();

// Render the cylinder on the crust as a handle
cylinderWithClipping();
}

module sliceSet() {
    translate([0, edge_length * -4, 0]) {
    for (i = [1:7]) { // Assuming you want to start from 1 and increment by 1 up to 10        
        translate([0, i * edge_length, 0]) 
            finalSlice();
    }
}
}


sliceSet();