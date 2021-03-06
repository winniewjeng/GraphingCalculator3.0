

#include "Interface.hpp"

Interface::Interface(): xmin(-4), xmax(4), grids(8), sidebar(), graph(), equation(xmin, xmax, grids){
    // some default values I can set the graph to
//    xmin(- 2 * 3.14), xmax(2 * 3.14), grids(8),
    window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Graphing Calculator");
    
    window.setFramerateLimit(100);
    
    // Change mouse type depending on where it is in window -- default to true
    mouseIn = true;
    if (cursor.loadFromSystem(sf::Cursor::Hand))
        window.setMouseCursor(cursor);
    
    // initialize equaiton memeber variable and plot
    equation.getCoords();
    
    // set the user define string function and print it on sidebar
    infix_expression = equation.get_expression();
    sidebar.set_infix_expression(infix_expression);
//     cout << infix_expression << endl;
    
}

// process events/update/render
void Interface::run() {
    
    while (window.isOpen()) {
        
        processEvents();
        update();
        render(); //clear/draw/display
    }
}


// clicking & stuff
void Interface::processEvents() {
    
    Event event;
    float mouseX, mouseY;
    while (window.pollEvent(event)) {
        
        switch (event.type) {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                switch(event.key.code) {
                        // user wants to quit program
                    case::Keyboard::Q:
                        window.close();
                        break;
                        //user wants to close program
                    case::Keyboard::Escape:
                        window.close();
                        break;
                        // user wants to pan right
                    case::Keyboard::Right:
                        command = PANRIGHT;
                        break;
                        // user wants to pan left
                    case::Keyboard::Left:
                        command = PANLEFT;
                        break;
                        // user wants to pan up
                    case::Keyboard::Up:
                        command = PANUP;
                        break;
                        // user wants to pan down
                    case::Keyboard::Down:
                        command = PANDOWN;
                        break;
                        // user wants to zoom in
                    case::Keyboard::I:
                        command = ZOOMIN;
                        break;
                    case::Keyboard::O:
                        command = ZOOMOUT;
                        break;
                        // user wants to zoom out
                }
            case Event::MouseEntered:
                mouseIn = true;
                break;
                
            case Event::MouseLeft:
                mouseIn = false;
                break;
                
            case Event::MouseMoved:
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
                //cout << mouseX << " " << mouseY << endl;
                // if mouseMoved in the sidebar, change cursor to text
                if (mouseX >= GRAPH_PANEL && mouseX <= WINDOW_WIDTH) {
                    if (cursor.loadFromSystem(sf::Cursor::Text))
                        window.setMouseCursor(cursor);
                    // if mouse is pressed inside sidebar, get user input
                } else {
                    if (cursor.loadFromSystem(sf::Cursor::Hand))
                        window.setMouseCursor(cursor);
                }
                break;
                
                
        }
        
    }
}

// update the graph -- check equation step
void Interface::update(){
    //cause changes to the data for the next frame
    equation.step(command);
    command = 0;
}

//clear/draw/display
void Interface::render() {
    
    window.clear();
    Draw();
    window.display();
    
}

//draw graph->sidebar->equation
void Interface::Draw() {
    
    graph.Draw(window);
    equation.Draw(window);
    sidebar.draw(window);
    
}
