$fn = 100; // Increase for smoother curves
inch_to_mm_conversion_factor = 25.4;
crust_height = 1.3 * inch_to_mm_conversion_factor; // Slice length from tip to crust in mm
slice_length = (1.4 * inch_to_mm_conversion_factor) - 1; // Crust height in mm
thickness = 0.10 * inch_to_mm_conversion_factor; // Thickness of the slice in mm
bite_size = slice_length/5;
cylinder_height = thickness * 5; // Height of the cylinder
cylinder_diameter = thickness * 1.2; // Diameter of the cylinder

hole_diameter = 3.25;

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
    slant1 = 1.6233;
    slant2 = -5;
    
    translate([0, -crust_height, -1]) 
    color("red")
    cube([bite_size, crust_height * 2, thickness * 2]);
    
    translate([1,0, 1]) {
        color("red");
        cylinder(h = thickness * 5, r = bite_size, center = true);
    }


        
    translate([crust_height * slant1, -(crust_height / 2) + (crust_height / trim_factor), -1]) 
    rotate([0, 0, 100])
    color("orange")
    cube([100, crust_height / 2, 5]);

    translate([crust_height - slant2, (crust_height / 2) + (crust_height / trim_factor), -1]) 
    rotate([0, 0, -100])
    color("orange")
    cube([100, crust_height / 2, 5]);

    translate([0, -(crust_height) + (crust_height / trim_factor), -1]) 
    color("blue")
    cube([100, crust_height / 2, 5]);

    translate([0, (crust_height / 2) - (crust_height / trim_factor), -1]) 
    color("blue")
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
    x_offset = 2.6;
    // Translate and rotate the cylinder to position it like a handle
    translate([slice_length - x_offset, 0, 3]) // Adjust for correct placement
    rotate([0, 30, 0]) // Tilted 45 degrees to intersect the crust
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
    clipping_cube_height = 2;
    top_offset = -0.7;
    translate([0, -crust_height, -thickness * clipping_cube_height]) // bottom cut
    color("red")
    cube([slice_length * 2, crust_height * 2, thickness * clipping_cube_height]);
    
    translate([0, -crust_height, thickness * clipping_cube_height + top_offset]) 
    color("blue")
    cube([slice_length * 2, crust_height * 2, (thickness * clipping_cube_height)]); // top cut
}

// Main module to render the final slice with all components
module finalSlice() {
    pizzaSliceWithClipping(); // Render the pizza slice with the clipping effect
    cylinderOnCrustWithClipping(); // Add the cylinder handle
}

// Render the final pizza slice
//finalSlice();

module drillHoles() {
    depth = -0.25;
    x0_translation = -0;
    x1_translation = 1;
    x2_translation = -0;
    y_offset = 7;
    
    translate([slice_length - (slice_length / 5) + x0_translation, y_offset, -thickness * depth]) // Adjust for correct 
    cylinder(h = thickness, d = hole_diameter, $fn = $fn, center = true);

    translate([slice_length - (slice_length / 5) + x1_translation, 0, -thickness * depth]) // Adjust for correct placement
    cylinder(h = thickness, d = hole_diameter, $fn = $fn, center = true);

    translate([slice_length - (slice_length / 5) + x0_translation, -y_offset, -thickness * depth]) // Adjust for correct 
    cylinder(h = thickness, d = hole_diameter, $fn = $fn, center = true);

}


module finalSliceWithText(slice_text, text_line_2, day_num, day) {
    colorToSet = day ? "#0F0FaF" : "white";
    color(colorToSet)
    scale([1.10, 1.025, 1]) {
        x_translation = ((day_num * slice_length) + 5) - ((slice_length * 8) / 2);    
        //text_line_2 = "foo";
        slice_text = slice_text[0];
        y_translation = (crust_height / 2) + 5;
        echo(text_line_2)
        if (day) {
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
}



module writetext(text, text_line_2) {
    // assuming default text size and font, adjust as needed
    font_size = thickness * 3.5;
    left = (slice_length / 1.9);
    top = (font_size / 2) + 1;
    line2top = top + font_size - 1;
    depth = -thickness - 2;
    translate([0, 0, depth]) {
        linear_extrude(thickness * 2) {// adjust the height to match the desired depth of the text engraving
            color("blue")
            translate([left, top - 1, 0]) {
                rotate([180, 0, 0])
                text(text, size = font_size, halign = "center", valign = "bottom"); // adjust text size and alignment as needed
            }
            
//            translate([left, line2top, 0]) {
//                rotate([180, 0, 0])
//                text(text_line_2, size = font_size, halign = "center", valign = "bottom"); // adjust text size and alignment as needed
//            }
        }
    }
}

// Example usage of finalSliceWithText

//translate([-4.2,21.8, 0]) 
{
    finalSliceWithText("Mon", "+", 1, true);
    finalSliceWithText("Tue", "+", 2, true);
    finalSliceWithText("Wed", "+", 3, true);
    finalSliceWithText("Thu", "+", 4, true);
    finalSliceWithText("Fri", "+", 5, true);
    finalSliceWithText("Sat", "+", 6, true);
    finalSliceWithText("Sun", "+", 7, true);
    finalSliceWithText("Mon", "-", 1, false);
    finalSliceWithText("Tue", "-", 2, false);
    finalSliceWithText("Wed", "-", 3, false);
    finalSliceWithText("Thu", "-", 4, false);
    finalSliceWithText("Fri", "-", 5, false);
    finalSliceWithText("Sat", "-", 6, false);
    finalSliceWithText("Sun", "-", 7, false);
}