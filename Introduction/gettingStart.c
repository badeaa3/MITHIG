// +------------------------------------------------------------------------------+ //
// Anthony Badea                                                                    //
//                                                                                  //
// Massachusetts Institute of Technology Class of 2019                              //
// Relativistic Heavy Ion Group                                                     //
// Department of Physics                                                            //
// Department of Mathematics                                                        //
// June 26, 2018                                                                    //
// +------------------------------------------------------------------------------+ //





/*
Hello there. If you are reading this it means you have fallen in love with physics and are ready to explore the wonders of nature! Particle
    physics, in particular, allows us to interact with nature at its most fundamental level. Modern facilities such as the Large Hadron Collider (LHC)
    at CERN, Geneva, Switzerland and the Relativistic Heavy Ion Collider (RHIC) at Brookhaven National Laboratory, New York, United States have pushed
    the boundaries of science and helped answer century old questions. Who are the people that are behind this effort? You've likely already met some
    of them and will certainly meet more in the future. Oh and of course you will soon become one of them!
 
Throughout these tutorials you will learn some of the skills necessary to begin conducting your own analysis. We will teach you the basics of C++, a coding language used throughout the physics community, and of ROOT, the scientific software framework used by CERN. Learning these tools is critical to conducting analysis in this field and will allow you to focus on the physics at hand. We intend for you to do most of the coding because that is simply the best way to learn -- try, fail, try again. Of course, we will provide a guiding hand but intend to teach you how to think in this context so it is critical that you experiment and ask questions.

So ... lets get going! In this exercise we see how to create a histogram, a skill so important that we want you to see it first.
 */





// C++ dependencies
#include <stdio.h>

// ROOT dependencies
#include "TH1F.h"
#include "TCanvas.h"

// Create a histogram and fill it with ten entries. Display histogram in a canvas. Returns an integer.
int gettingStarted()
{
    
    // First we decide how many bins we wish to have and what range will be working in. For each value we declare an int (integer) with a name and assign it the corresponding value.
    int numberOfBins = 5;
    int histoMin = 0;
    int histoMax = 10;
    
    // Second, "construct" a TH1F "object" is constructed. Since C++ is an object oriented programming, it is centered around "objects" and methods. Below we construct a TH1F object using the default constructor given by the TH1F class. The F stands for float since this histogram is intended to be filled with floats, a fundamental type within the floating point category of C++.
    TH1F *histoName = new TH1F("histoName","histoTitle;XaxisTitle;YaxisTitle",numberOfBins,histoMin,histoMax);
    
    // Third, we use a for loop to fill the histogram. This will add an entry into the bin corresponding to the value 1.0 for each iteration of the loop.
    int numberOfLoops = 10;
    for (int i = 0; i < numberOfLoops; i++)
    {
        histoName->Fill(1.0);
    }
    
    // Fourth, we construct a TCanvas to draw the histogram to. This is how you will display a histogram created within a function.
    TCanvas *canvasName = new TCanvas("canvasName","canvasTitle",500,500);
    histoName->DrawCopy();
    
    // Fifth, don't forget to clean up by deleting new objects. The delete method deallocates the memory block pointed to by a "pointer". Rather than containing the data itself, the name that you give each object points to the object in memory. So when we delete the pointer we release the storage space previously allocated to it and render that pointer location invalid. When deleting operate on the Last in - First out (LIFO) principle. Delete the object that was made most recently and work your way backwards. It is crucial that you do this so that your future methods do not pick up data accidentally left in memory.
    
    // Do not delete the canvas because we wish to view it after the function finishing.
    delete histoName;
    
    // Return an integer as this is what the method declaration requires
    return 0;
}
