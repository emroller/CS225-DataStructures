 #include <iostream>
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <cassert>
#include <algorithm>
#include <functional>

#include "Image.h"  

   void Image::darken() {
     
     for (unsigned x = 0; x < this->width(); x++) {
       for (unsigned y = 0; y < this->height(); y++) {
	 cs225:: HSLAPixel & pixel = this->getPixel(x,y);
	 if (pixel.l < 0.1) {
	   pixel.l = 0;
	 } else {
	   pixel.l -= 0.1;
	 }
       }
     }
   }

   void Image::darken(double amount) {

     for (unsigned x = 0; x < this->width(); x++) {
       for (unsigned y = 0; y < this->height(); y++) {
	 cs225:: HSLAPixel & pixel = this->getPixel(x,y);
         if (pixel.l - amount < 0) {
           pixel.l = 0;
         } else {
           pixel.l -= amount;
         }
       }
     }
   }

   void Image::desaturate() {

     for (unsigned x = 0; x < this->width(); x++) {
       for (unsigned y = 0; y < this->height(); y++) {
	 cs225:: HSLAPixel & pixel = this->getPixel(x,y);
         if (pixel.s < 0.1) {
           pixel.s = 0;
         } else {
           pixel.s -= 0.1;
         }
       }
     }
   }

   void Image::desaturate(double amount) {

     for (unsigned x = 0; x < this->width(); x++) {
       for (unsigned y = 0; y < this->height(); y++) {
	 cs225:: HSLAPixel & pixel = this->getPixel(x,y);
         if (pixel.s - amount < 0) {
           pixel.s = 0;
         } else {
           pixel.s -= amount;
         }
       }
     }

   }

   void Image::grayscale() {
     for (unsigned x = 0; x < this->width(); x++) {
       for (unsigned y = 0; y < this->height(); y++) {
	 cs225:: HSLAPixel & pixel = this->getPixel(x, y);
	 pixel.s = 0;
       }
     }
   }

   void Image::illinify() {
     for (unsigned int x = 0; x < this->width(); x++) {
       for (unsigned int y = 0; y < this->height(); y++) {
	 cs225::HSLAPixel & pixel = this->getPixel(x, y);
	 // if the pixel hue is exactly in between 11 and 216, set it to orange
	 if (pixel.h <= 113.5 || pixel.h >= 293.5) {
	   pixel.h = 11.0;
	 } else if (pixel.h > 113.5 && pixel.h < 293.5) {
	   pixel.h = 216.0;
	 }
       }
     } 
   }

   void Image::lighten() {
     for (unsigned x = 0; x < this->width(); x++) {
       for (unsigned y = 0; y < this->height(); y++) {
	 cs225:: HSLAPixel & pixel = this->getPixel(x,y);
         if (pixel.l > 0.9) {
           pixel.l = 1.0;
         } else {
           pixel.l += 0.1;
         }
       }
     }

   }

   void Image::lighten(double amount) {
     for (unsigned x = 0; x < this->width(); x++) {
       for (unsigned y = 0; y < this->height(); y++) {
	 cs225:: HSLAPixel & pixel = this->getPixel(x,y);
         if (pixel.l + amount > 1.0) {
           pixel.l = 1.0;
         } else {
           pixel.l += amount;
         }
       }
     }
   }

   void Image::rotateColor(double degrees) {
     for (unsigned x = 0; x < this->width(); x++) {
       for (unsigned y = 0; y < this->height(); y++) {
	 cs225:: HSLAPixel & pixel = this->getPixel(x,y);
	 if (pixel.h + degrees < 0) {
	    pixel.h = 360 + (pixel.h + degrees);
	 } else if (pixel.h + degrees > 360) {
	    pixel.h = (pixel.h + degrees) - 360;
	 } else {
	    pixel.h += degrees;
	 }
       }
     }
   }

   void Image::saturate() {
   for (unsigned x = 0; x < this->width(); x++) {
       for (unsigned y = 0; y < this->height(); y++) {
         cs225:: HSLAPixel & pixel = this->getPixel(x,y);
         if (pixel.s > 0.9) {
           pixel.s = 1.0;
         } else {
           pixel.s +=0.1;
         }
       }
     }

   }

   void Image::saturate(double amount) {
   for (unsigned x = 0; x < this->width(); x++) {
       for (unsigned y = 0; y < this->height(); y++) {
         cs225:: HSLAPixel & pixel = this->getPixel(x,y);
         if (pixel.s + amount > 1.0) {
           pixel.s = 1.0;
         } else {
           pixel.s += amount;
         }
       }
     }

   }

   void Image::scale(double factor) {
	cs225::PNG* old_image = new cs225::PNG(*this);
	
	//resize this to new dimensions
	resize(this->width() * factor, this->height() * factor);
	
	for (unsigned x = 0; x < this->width(); x++) {
           for (unsigned y = 0; y < this->height(); y++) {
              cs225::HSLAPixel & pixel = this->getPixel(x,y);
 	      pixel = old_image->getPixel(x/factor,y/factor);
           }
	 }
	delete old_image; 
   }
   void Image::scale(unsigned w, unsigned h) {
	w = (double)w;
	h = (double)h;
	double x = (double)this->width();
	double y = (double)this->height();
	
	double x_fact = (w/x);
	double y_fact = (h/y);
	double factor = std::min(x_fact, y_fact);	
	scale(factor);

   }

    int Image::getX() {
	return x_;
    }

    int Image::getY() {
	return y_;
    }

    int Image::getIndex() {
	return index_;
    }
    
    void Image::setX(int x) {
	x_ = x;
    }
    
    void Image::setY(int y) {
	y_ = y;
    }
    
    void Image::setIndex(int index) {
	index_ = index;
    }
