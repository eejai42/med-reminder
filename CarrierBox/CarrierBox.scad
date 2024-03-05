// Credit Card Box Dimensions
BOX_LENGTH = 87;
BOX_WIDTH = 55;
BOX_HEIGHT = 50;
WALL_THICKNESS = 2;
HOVER_GAP = 5;
LID_THICKNESS = 3;
INSET_WIDTH = 2;
INSET_HEIGHT = 3;
INSET_GAP = 10.5;

// Lid Clearance
LID_CLEARANCE = 0.2; // Small gap for easy lid fitting
LID_HEIGHT = 5; // Height of the lid

// Function to create the main box
module box() {
    difference() {
        // Outer dimensions
        cube([BOX_LENGTH + 2*WALL_THICKNESS, BOX_WIDTH + 2*WALL_THICKNESS, BOX_HEIGHT]);
        // Inner cavity
        translate([WALL_THICKNESS, WALL_THICKNESS, WALL_THICKNESS])
        cube([BOX_LENGTH, BOX_WIDTH, BOX_HEIGHT + WALL_THICKNESS]); // Extend inner cavity into the lid area for a flush fit
    }
}

// Updated function to create the lid with an inset
module lid() {
    // Outer lid
    translate([0, 0, BOX_HEIGHT + HOVER_GAP])
    cube([BOX_LENGTH + 2*WALL_THICKNESS, BOX_WIDTH + 2*WALL_THICKNESS, LID_THICKNESS]);

    // Inset for the lid to fit into the box
    translate([WALL_THICKNESS + floor(INSET_GAP/2), WALL_THICKNESS + floor(INSET_GAP/2), BOX_HEIGHT + HOVER_GAP + (LID_THICKNESS * -1)])
    cube([(BOX_LENGTH + 2*(WALL_THICKNESS - INSET_WIDTH) - INSET_GAP), (BOX_WIDTH + 2*(WALL_THICKNESS - INSET_WIDTH) - INSET_GAP), INSET_HEIGHT]);
}

// Rendering the box and lid
box();
lid();
