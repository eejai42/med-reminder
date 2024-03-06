// Credit Card Box Dimensions
BOX_LENGTH = 89;
BOX_WIDTH = 61;
BOX_HEIGHT = 75;
WALL_THICKNESS = 1;
HOVER_GAP = 5;
LID_THICKNESS = 1;
INSET_WIDTH = 1;
INSET_HEIGHT = 2;
INSET_GAP = 10.5;

 // Adding posts in each corner
// Post dimensions
POST_SIZE = 3;
POST_WIDTH = POST_SIZE;
POST_DEPTH = POST_SIZE;
POST_HEIGHT = BOX_HEIGHT / 2;

// Lid Clearance
LID_CLEARANCE = 0.2; // Small gap for easy lid fitting
LID_HEIGHT = 5; // Height of the lid

// New constants for drilling holes
HOLE_DIAMETER = 5; // Diameter of each hole
HOLE_Y_DISTANCE = BOX_HEIGHT - (BOX_HEIGHT / 4); // Distance of holes from the base of the box

// USB details
USB_HEIGHT = BOX_HEIGHT / 10;
USB_WIDTH = BOX_WIDTH / 5;
USB_X_OFFSET = (BOX_WIDTH / 5);
USB_Y_OFFSET = (POST_HEIGHT) - (USB_HEIGHT * 1 + (USB_HEIGHT / 3));

// Function to create the main box
module box() {
    difference() {
        // Outer dimensions
        cube([BOX_LENGTH + 2*WALL_THICKNESS, BOX_WIDTH + 2*WALL_THICKNESS, BOX_HEIGHT]);
        // Inner cavity
        translate([WALL_THICKNESS, WALL_THICKNESS, WALL_THICKNESS])
        cube([BOX_LENGTH, BOX_WIDTH, BOX_HEIGHT + WALL_THICKNESS]); // Extend inner cavity into the lid area for a flush fit
    }
    
      
    // Bottom left front post
    translate([WALL_THICKNESS, WALL_THICKNESS, WALL_THICKNESS])
    cube([POST_WIDTH, POST_DEPTH, POST_HEIGHT]);
    
    // Bottom right front post
    translate([BOX_LENGTH + WALL_THICKNESS - POST_WIDTH, WALL_THICKNESS, WALL_THICKNESS])
    cube([POST_WIDTH, POST_DEPTH, POST_HEIGHT]);
    
    // Bottom left back post
    translate([WALL_THICKNESS, BOX_WIDTH + WALL_THICKNESS - POST_DEPTH, WALL_THICKNESS])
    cube([POST_WIDTH, POST_DEPTH, POST_HEIGHT]);
    
    // Bottom right back post
    translate([BOX_LENGTH + WALL_THICKNESS - POST_WIDTH, BOX_WIDTH + WALL_THICKNESS - POST_DEPTH, WALL_THICKNESS])
    cube([POST_WIDTH, POST_DEPTH, POST_HEIGHT]);
}

// Function to drill holes into the long side of the box
module drillHoles() {
    for(i = [1:4]) {
        translate([
            WALL_THICKNESS + (BOX_LENGTH - (3 * HOLE_DIAMETER)) * i / 4, // Evenly space along the length, adjusting for hole diameter
            BOX_WIDTH + 2*WALL_THICKNESS + 1, // Position to drill through the wall thickness
            HOLE_Y_DISTANCE
        ])
        rotate([90, 0, 0])
        cylinder(d = HOLE_DIAMETER, h = WALL_THICKNESS * 2, $fn=50);
    }
    
    translate([-1, USB_X_OFFSET, USB_Y_OFFSET]) {
        rotate([0, 0, 0])
        cube([WALL_THICKNESS * 3, USB_WIDTH, USB_HEIGHT]);
    }
}

// Function to create the box with holes
module boxWithHoles() {
    difference() 
    {
        // Original box design
        box();
        // Drill holes
        drillHoles();
    }
}

// Updated function to create the lid with an inset
module lid() {
    // Outer lid
    translate([0, 0, BOX_HEIGHT + HOVER_GAP])
    cube([BOX_LENGTH + 2*LID_THICKNESS, BOX_WIDTH + 2*LID_THICKNESS, LID_THICKNESS]);

    // Inset for the lid to fit into the box
//    translate([WALL_THICKNESS + floor(INSET_GAP/2), WALL_THICKNESS + floor(INSET_GAP/2), BOX_HEIGHT + HOVER_GAP + (LID_THICKNESS * -1)])
    translate([WALL_THICKNESS * 2, WALL_THICKNESS * 2, BOX_HEIGHT + HOVER_GAP + (LID_THICKNESS * -1)])
    color("red")
    cube([(BOX_LENGTH - (WALL_THICKNESS * 2)), BOX_WIDTH - (WALL_THICKNESS * 2), LID_THICKNESS]);
}

module rotateLid() {
    translate([-(LID_THICKNESS + HOVER_GAP), 0, BOX_HEIGHT + (LID_THICKNESS * 6)])
    rotate([0, 180, 0])
    lid();
}

// Rendering the box and lid
boxWithHoles();
//rotateLid();
