$fn = 100; // Increase for smoother curves
inch_to_mm_conversion_factor = 25.4;
crust_height = 1.2 * inch_to_mm_conversion_factor; // Slice length from tip to crust in mm
slice_length = 1.2 * inch_to_mm_conversion_factor; // Crust height in mm
thickness = 0.10 * inch_to_mm_conversion_factor; // Thickness of the slice in mm
bite_size = slice_length/5;
cylinder_height = thickness * 3; // Height of the cylinder
cylinder_diameter = thickness / 1.15; // Diameter of the cylinder

hole_diameter = 3.5;

function calculateSlicePoints(slice_length, crust_height) = 
    let(half_base = crust_height / 2)
    [
        [0, 0], // Tip of the slice
        [slice_length, half_base], // Right crust edge
        [slice_length, -half_base] // Left crust edge
    ];


// Pizza slice footprint with dynamically calculated points
module pizzaSliceFootprint() {
    color("blue") 
    polygon(points=calculateSlicePoints(slice_length, crust_height));    
}

// Clipping cube to trim the pizza slice tip
module clippingCube() {
    trim_factor = 10;
    slant1 = 1.554;
    slant2 = -2.5;
translate([0, -crust_height, -1]) 
color("blue")
cube([bite_size, crust_height * 2, thickness * 2]);

translate([0, -(crust_height) + (crust_height / trim_factor), -1]) 
color("red")
cube([100, crust_height / 2, 5]);
    
    translate([crust_height * slant1, -(crust_height / 2) + (crust_height / trim_factor), -1]) 
    rotate([0, 0, 100])
    color("orange")
    cube([100, crust_height / 2, 5]);


translate([0, (crust_height / 2) - (crust_height / trim_factor), -1]) 
color("blue")
cube([100, crust_height / 2, 5]);

    translate([crust_height - slant2, (crust_height / 2) + (crust_height / trim_factor), -1]) 
    rotate([0, 0, -100])
    color("orange")
    cube([100, crust_height / 2, 5]);

}

// Extruding the footprint to create the slice with clipping effect
module pizzaSliceWithClipping() {
    difference() 
    {
        linear_extrude(height = thickness) {
            pizzaSliceFootprint();
        }
        clippingCube();
    }
}

// Adding the cylinder on the crust as a handle
module cylinderOnCrust() {
    
    // Translate and rotate the cylinder to position it like a handle
    translate([slice_length, 0, cylinder_height / 2]) // Adjust for correct placement
    rotate([0, 45, 0]) // Tilted 45 degrees to intersect the crust
    cylinder(h = cylinder_height, d = cylinder_diameter, $fn = $fn, center = true);
}

module cylinderOnCrustWithClipping() {
    difference()
    {
        cylinderOnCrust();
        cylinderClippingCube();
    }
}

module cylinderClippingCube() {
    translate([0, -crust_height  / 2, thickness * 1.75]) 
    color("blue")
    cube([slice_length * 2, crust_height * 2, thickness * 5]);
}

// Main module to render the final slice with all components
module finalSlice() {
    pizzaSliceWithClipping(); // Render the pizza slice with the clipping effect
    cylinderOnCrustWithClipping(); // Add the cylinder handle
}

// Render the final pizza slice
//finalSlice();

module drillHoles() {
    depth = 0.0;
    
    translate([slice_length - (slice_length / 5), 0, -thickness * depth]) // Adjust for correct placement
    cylinder(h = thickness, d = hole_diameter, $fn = $fn, center = true);

    translate([slice_length - (slice_length / 5), 5, -thickness * depth]) // Adjust for correct 
    cylinder(h = thickness, d = hole_diameter, $fn = $fn, center = true);


    translate([slice_length - (slice_length / 5), -5, -thickness * depth]) // Adjust for correct 
    cylinder(h = thickness, d = hole_diameter, $fn = $fn, center = true);

}


module finalSliceWithText(slice_text, text_line_2, day_num) {
    x_translation = ((day_num * slice_length) + 5) - ((slice_length * 8) / 2);

    y_translation = (crust_height / 2) + 5;
    echo(text_line_2)
    if (text_line_2 == "day") {
        echo("UPDATING y TRANSLATION");
        y_translation = -y_translation;
        translate([x_translation, y_translation, 0]) {
            difference() 
            {
                {
                    finalSlice();
                    writetext(slice_text, text_line_2);
                }
                drillHoles();
            }
        }
    } else {
        translate([x_translation, y_translation, 0]) {
        difference() 
        {
            {
                finalSlice();
                writetext(slice_text, text_line_2);
            }
            drillHoles();
        }
    }

}
}



module writetext(text, text_line_2) {
    // assuming default text size and font, adjust as needed
    font_size = thickness * 1.6;
    left = (slice_length / 2);
    top = (font_size / 4);
    line2top = top + font_size;
    depth = -thickness - 1.5;
    translate([0, 0, depth]) {
        linear_extrude(thickness * 2) {// adjust the height to match the desired depth of the text engraving
            color("blue")
            translate([left, top - 1, 0]) {
                rotate([180, 0, 0])
                text(text, size = font_size, halign = "center", valign = "bottom"); // adjust text size and alignment as needed
            }
            
            translate([left, line2top, 0]) {
                rotate([180, 0, 0])
                text(text_line_2, size = font_size, halign = "center", valign = "bottom"); // adjust text size and alignment as needed
            }
        }
    }
}

// Example usage of finalSliceWithText
finalSliceWithText("Mon", "day", 1);
finalSliceWithText("Tue", "day", 2);
finalSliceWithText("Wed", "day", 3);
finalSliceWithText("Thu", "day", 4);
finalSliceWithText("Fri", "day", 5);
finalSliceWithText("Sat", "day", 6);
finalSliceWithText("Sun", "day", 7);
finalSliceWithText("Mon", "eve", 1);
finalSliceWithText("Tue", "eve", 2);
finalSliceWithText("Wed", "eve", 3);
finalSliceWithText("Thu", "eve", 4);
finalSliceWithText("Fri", "eve", 5);
finalSliceWithText("Sat", "eve", 6);
finalSliceWithText("Sun", "eve", 7);
//
//
//// sliceSet();