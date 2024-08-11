

// a)
// Shows a triangle with the squares on each side.
void pythagoras() {

    using namespace Graph_lib;

    // width and height of the window.
    const int w = 1000;
    const int h = 800;

    // Start position for the triangle.
    const int startX = w/2 - 100;
    const int startY = h/2 + 100;

    // Dimensions for the triangle
    const int triangleWidth = 200;
    const int triangleHeight = 150;

    // Initializing our window.
    Simple_window win{Point{100, 100}, w, h, "Pythagoras"};

    // The following will add figures, by adding points and drawing lines between them.
    Polygon rightTriangle;
    // Makes the width of the triangle (a-side)
    rightTriangle.add(Point{startX, startY});
    rightTriangle.add(Point{startX + triangleWidth, startY});
    // Makes the height of the triangle (b-side)
    rightTriangle.add(Point{startX + triangleWidth, startY - triangleHeight});
    rightTriangle.set_fill_color(Color::red);

    // the a-side of the triangle
    Polygon triangleSquare_a;
    triangleSquare_a.add(Point{startX, startY});
    triangleSquare_a.add(Point{startX + triangleWidth, startY});
    triangleSquare_a.add(Point{startX + triangleWidth, startY + triangleWidth});
    triangleSquare_a.add(Point{startX, startY + triangleWidth});
    triangleSquare_a.set_fill_color(Color::dark_gray);
    // The b-side of the triangle
    Polygon triangleSquare_b;
    triangleSquare_b.add(Point{startX + triangleWidth, startY});
    triangleSquare_b.add(Point{startX + triangleWidth, startY - triangleHeight});
    triangleSquare_b.add(Point{startX + triangleWidth + triangleHeight, startY - triangleHeight});
    triangleSquare_b.add(Point{startX + triangleWidth + triangleHeight, startY});
    triangleSquare_b.set_fill_color(Color::dark_gray);
    // the c-side of the triangle (hypotenus)
    Polygon triangleSquare_c;
    triangleSquare_c.add(Point{startX + triangleWidth, startY - triangleHeight});
    triangleSquare_c.add(Point{startX, startY});
    triangleSquare_c.add(Point{startX - triangleHeight, startY - triangleWidth});
    triangleSquare_c.add(Point{startX + triangleWidth - triangleHeight, startY - triangleHeight - triangleWidth});
    triangleSquare_c.set_fill_color(Color::dark_gray);
    
    // Attaches the graphics to our window.
    win.attach(rightTriangle);
    win.attach(triangleSquare_a);
    win.attach(triangleSquare_b);
    win.attach(triangleSquare_c);

    // Exits program when button in top right of window is clicked.
    win.wait_for_button();
}
