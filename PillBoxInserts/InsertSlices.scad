// Parameters
$fn = 100; // Increase for smoother curves
edge_length = 30; // Edge length in mm, assuming 3cm as per initial requirement
thickness = 1; // Thickness of the slice in mm

// Pizza slice footprint
module pizzaSliceFootprint() {
    // Drawing the two edges
    rotate([0,0,-90]) // Rotate to start the first edge from the bottom going up
    translate([0,0])
    polygon(points=[[0,0], [edge_length,0], [edge_length*cos(60), edge_length*sin(60)], [0,0]]);
}

// Extruding the footprint to create the slice
module pizzaSlice() {
    linear_extrude(height = thickness) {
        pizzaSliceFootprint();
    }
}

// Render the pizza slice
pizzaSlice();
