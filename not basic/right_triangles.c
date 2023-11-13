#include <stdio.h>
// Utility function prototypes that abstract code
// into direct descriptions of the aspects involved in printing a triangle
int get_size(int* rows);
int get_orientation(int* orientation);
int get_choice_if_hollow_or_not(int* is_hollow);
int is_triangle_still_incomplete(int i, int rows);
int is_row_still_incomplete(int j, int rows);
int at_hypotenuse(int i, int j, int edge, int orient);
int at_vert_side(int j, int edge, int orient);
int at_hori_size(int i, int edge, int orient);
int ifNotHollow(int is_hollow, int i, int j, int edge, int orient);

// Main triangle maker function. Go ahead and study this function, which is located right below main().
void print_right_triangle(int rows, int orientation, int is_hollow);

int main()
{
  int rows, orientation, is_hollow, repeat = 0;
  // The bulk of the program is inside this do-while loop.
  do
  {
    printf("Make a right triangle!");
    // Take input for row size, keep on repeating until input is valid, i.e., row > 0
    while (get_size(&rows) < 0);
    
    // if statement acting as an exit option to terminate the program immediately
    if (!rows) return 0;
    
    // Take input for triangle orientation (where it is facing), repeated until input is valid
    while (get_orientation(&orientation), (orientation < 1 || orientation > 4));

    // Take input letting the user choose either a hollow triangle or a solid one
    while (get_choice_if_hollow_or_not(&is_hollow), (is_hollow != 1 && is_hollow != 0));

    // The triangle is printed inside this function;
    print_right_triangle(rows, orientation, is_hollow);

    printf("Make more triangles? (0-no, 1-yes) ");
    scanf("%d", &repeat);
  } while (repeat); // do-while stops only when repeat == 0, otherwise it continues (yeah, it's just personal preferrence to leave out the negative numbers ;) ) 

  return 0;
}

// ************************************************************************************************************
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv--EYES ON THIS FUNCTION FIRST!--vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

void print_right_triangle(int rows, int orientation, int is_hollow)
{
  const int EDGE = rows - 1;
  const int O = orientation;
  // Constructs the triangle across the terminal window like plotting points on a coordinate system
  // Outer loop moves the terminal cursor through rows, or across the i-axis (or y-axis if you prefer), from top to bottom
  // Outer loop only stops when cursor completes the entire last row (when is_triangle_still_incomplete() == false)
  for (int i = 0; is_triangle_still_incomplete(i,rows); ++i)
  {
    // Inner loop moves the terminal cursor through columns, or across the j-axis (x-axis), from left to right
    // Inner loop contains the actual printing of individual characters, and whether "*" or " " is printed.
    for (int j = 0; is_row_still_incomplete(j,rows); ++j)
    {
      // if block checks if current (j, i) coordinate corresponds to a point on the correct triangle and prints an "*" if it does
      // else block puts a space on the rest of the coordinates that aren't part of the triangle
      if (at_hypotenuse(i, j, EDGE, O) || at_vert_side(j, EDGE, O) || at_hori_size(i, EDGE, O) || ifNotHollow(is_hollow, i, j, EDGE, O)) printf("*");
      else printf(" ");
    }
    printf("\n"); // Moves terminal cursor to the next row, don't forget to add this!
  }
}

// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^--EYES ON THIS FUNCTION FIRST!--^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// ************************************************************************************************************

// Auxiliary functions (submodules) to make the triangle function more abstract and simpler to understand

// Checks if more rows are to be printed or not, serves as outer loop condition
int is_triangle_still_incomplete(int i, int rows) 
{
  return i < rows; // True (1) if triangle is not yet done, False (0) if it is done
}

// Checks if more columns are to be printed in current row, serves as inner loop condition
int is_row_still_incomplete(int j, int rows) 
{
  return j < rows; // True (1) if current row is not yet fully-printed, False (0) otherwise
}

// Checks if current (j, i) coordinate is part of the triangle's hypotenuse: True (1) if it is, otherwise False (0)
int at_hypotenuse(int i, int j, int edge, int orient) 
{
  const int POSITIVELY_SLOPED_HYPOTENUSE = edge - i; // If hypotenuse tilts forward like a "/"
  const int NEGATIVELY_SLOPED_HYPOTENUSE = i; // If hypotenuse tilts backward like a "\"
  // Compares the j value to the appropriate hypotenuse values, which depends on the triangle's orientation
  switch (orient) 
  {
    case 1: case 3: // Right Angle is Bottom-Left or Top-Right; They have the same hypotenuse position
      return j == NEGATIVELY_SLOPED_HYPOTENUSE; // It is only true if it is on the hypotenuse
    case 2: case 4: // Right Angle is Bottom-Right or Top-Left; They have the same hypotenuse position
      return j == POSITIVELY_SLOPED_HYPOTENUSE; // It is only true if it is on the hypotenuse
  }
  return 0; // Failsafe just in case orient does not satisfy switch()
}

// Checks if current (j, i) coordinate is part of the triangle's vertical side: True (1) if it is, otherwise False (0)
int at_vert_side(int j, int edge, int orient) 
{
  const int VERTICAL_SIDE_IS_ON_THE_LEFT = 0; // Which is when j == 0 (very first column)
  const int VERTICAL_SIDE_IS_ON_THE_RIGHT = edge; // Which is when j == rows - 1 (very last column)
  // Compares the j value to the appropriate line values, which depends on where the triangle is facing
  switch (orient) 
  {
    case 1: case 4: // Right Angle is Bottom-Left or Top-Left; They have the same vertical side
      return j == VERTICAL_SIDE_IS_ON_THE_LEFT; // It is only true if the current j is on the line
    case 2: case 3: // Right Angle is Bottom-Right or Top-Right; They have the same vertical side
      return j == VERTICAL_SIDE_IS_ON_THE_RIGHT;
  }
  return 0;
}

// Checks if current (j, i) coordinate is part of the triangle's vertical side: True (1) if it is, otherwise False (0)
int at_hori_size(int i, int edge, int orient) 
{
  const int HORIZONTAL_SIDE_IS_FIRST_ROW = 0; // Which is when i == 0 (very first row)
  const int HORIZONTAL_SIDE_IS_LAST_ROW = edge; // Which is when i == rows - 1 (very last row);
  // Compares the j value to the appropriate line values, which depends on where the triangle is facing
  switch (orient) 
  {
    case 1: case 2: // Right Angle is Bottom-Left or Bottom-Right; They have the same horizontal side
      return i == HORIZONTAL_SIDE_IS_LAST_ROW; // It is only true if the current i is on the line
    case 3: case 4: // Right Angle is Top-Right or Top-Left; They have the same horizontal side
      return i == HORIZONTAL_SIDE_IS_FIRST_ROW;
  }
  return 0;
}

// Checks if user wants a hollow triangle or not, and checks if the current (j, i) point is part of the triangle's body (the inside part, excluding the sides)
// ifNotHollow only returns true if the user wants a solid triangle and if the current point is on the body
int ifNotHollow(int is_hollow, int i, int j, int edge, int orient) 
{
  if (is_hollow) return 0;
  const int NEGATIVE_HYPOTENUSE_POSITION_AT_J_AXIS = i; // Stores the j value of the hypotenuse (j=i) at current row
  const int POSITIVE_HYPOTENUSE_POSITION_AT_J_AXIS = edge - i; // Stores the j value of the hypotenuse at current row
  // Since hypotenuse position depends on the triangle's orientation, there are different conditions for each orientation
  switch (orient) 
  {
    case 1: // Right Angle is Bottom-Left
      return j < NEGATIVE_HYPOTENUSE_POSITION_AT_J_AXIS; // Triangle's body is always on the hypotenuse's left side (<)
    case 2: // Right Angle is Bottom-Right
      return j > POSITIVE_HYPOTENUSE_POSITION_AT_J_AXIS; // Triangle's body is always on the hypotenuse's right side (>)
    case 3: // Right Angle is Top-Right
      return j > NEGATIVE_HYPOTENUSE_POSITION_AT_J_AXIS; // Triangle's body is always on the hypotenuse's right side (>)
    case 4: // Right Angle is Top-Left
      return j < POSITIVE_HYPOTENUSE_POSITION_AT_J_AXIS; // Triangle's body is always on the hypotenuse's left side (<)
  }
  return 0;
}


// Utility functions not necessary to understand how to print triangles;
int get_size(int* rows) 
{
  printf("\nHow many rows? ");
  scanf("%d", rows);
  return *rows;
}
int get_orientation(int* orientation) 
{
  printf("\n[1] Right Angle is Bottom-Left");
  printf("\n[2] Right Angle is Bottom-Right");
  printf("\n[3] Right Angle is Top-Right");
  printf("\n[4] Right Angle is Top-Left");
  printf("\nChoose orientation from above choices: ");
  scanf("%d", orientation);
  return *orientation;
}
int get_choice_if_hollow_or_not(int* is_hollow) 
{
  printf("\nWant a hollow triangle? (0: no, 1: yes) ");
  scanf("%d", is_hollow);
  return *is_hollow;
}
