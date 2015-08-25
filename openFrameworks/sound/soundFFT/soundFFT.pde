import ddf.minim.analysis.*;
import ddf.minim.*;

Minim       minim;
AudioPlayer song;
FFT         fft;

void setup()
{
  size(512, 200, P3D);
  
  minim = new Minim(this);
  
  // specify that we want the audio buffers of the AudioPlayer
  // to be 1024 samples long because our FFT needs to have 
  // a power-of-two buffer size and this is a good size.
  song = minim.loadFile("song.mp3", 1024);
  
  // loop the file indefinitely
  song.loop();
  
  // create an FFT object that has a time-domain buffer 
  // the same size as song's sample buffer
  // note that this needs to be a power of two 
  // and that it means the size of the spectrum will be half as large.
  fft = new FFT( song.bufferSize(), song.sampleRate() );
  
}

void draw()
{
  background(0);
  stroke(255);
  
  // perform a forward FFT on the samples in song's mix buffer,
  // which contains the mix of both the left and right channels of the file
  fft.forward( song.mix );
  
  for(int i = 0; i < fft.specSize(); i++)
  {
    // draw the line for frequency band i, scaling it up a bit so we can see it
    line( i, height, i, height - fft.getBand(i)*8 );
  }
}
