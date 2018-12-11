//
//  Equation.cpp
//  Calculator3.0
//
//  Created by Winnie Jeng on 12/5/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#include "Equation.hpp"

void Equation::getCoords(double xmin, double xmax, double grids) {
    
    xyCoords.clear();
    
    cout << "Postfix: " << postfix_queue << endl;
    
    double xrange = xmax - xmin;
    
    for (double xpixel = 0; xpixel <= GRAPH_PANEL; xpixel++) {
        
        double xval = xmin + (xpixel / GRAPH_PANEL) * xrange;
        // evaluate y
        double yval = yard.Eval(postfix_queue, xval);

        // get y pixel
        double ypixel = (1 - (yval / grids * 2) ) * WINDOW_HEIGHT / 2;

////        //if yval == 0, use pixel to plot x-axis
        if (xval == 0) {
            Vertex yVertex[3];
            yVertex[0].position = Vector2f(xpixel, 0);
            yVertex[0].color = Color::White;
            yAxis.append(yVertex[0]);
            yVertex[1].position = Vector2f(xpixel, ypixel);
            yVertex[1].color = Color::White;
            yAxis.append(yVertex[1]);
            yVertex[2].position = Vector2f(xpixel, WINDOW_HEIGHT);
            yVertex[2].color = Color::White;
            yAxis.append(yVertex[2]);
        }
        if (yval == 0) {
            Vertex xVertex[3];
            // left-most point is (xminPixel, ypixel)
            // middle point is (xpixel, ypixel)
            xVertex[0].position = Vector2f(0, ypixel);
            xVertex[0].color = Color::White;
            xAxis.append(xVertex[0]);
            xVertex[1].position = Vector2f(xpixel, ypixel);
            xVertex[1].color = Color::White;
            xAxis.append(xVertex[1]);
            xVertex[2].position = Vector2f(GRAPH_PANEL, ypixel);
            xVertex[2].color = Color::White;
            xAxis.append(xVertex[2]);
        }
        
        //store pixel location inside a vertex
        Vertex vertex;
        vertex.position = Vector2f(xpixel, ypixel);
        // make the graph orange color
        vertex.color = Color(255, 150, 0);
        // append the vertex to xyCoords;
        xyCoords.append(vertex);
    }
}

void Equation::Draw(sf::RenderWindow& window)
{
    window.draw(yAxis);
    window.draw(xAxis);
    window.draw(xyCoords);
    _graphDrawn = true;
}

