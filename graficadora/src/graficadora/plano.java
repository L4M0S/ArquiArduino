package graficadora;
import com.panamahitek.ArduinoException;
import com.panamahitek.PanamaHitek_Arduino;
import java.awt.Color;
import java.awt.Graphics;
import static java.lang.Math.pow;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.BorderFactory;
import javax.swing.JPanel;
import jssc.SerialPortEvent;
import jssc.SerialPortEventListener;
import jssc.SerialPortException;
/**
 *
 * @author jorge
 */
public class plano extends JPanel{


    public plano() {
        try {
            ino.arduinoRX("COM4", 9600, listener);
        } catch (ArduinoException | SerialPortException ex) {
            Logger.getLogger(Graficadora.class.getName()).log(Level.SEVERE, null, ex);
        }
        init();
    }

    public void init() {
        this.setBorder(BorderFactory.createLineBorder(Color.black));
    }

    @Override 
     public void paintComponent( Graphics g ) {     //EJE X y Y
                    super.paintComponent(g);

                    g.setColor(Color.red);

                    g.drawLine(0, this.getHeight()/2, this.getWidth(), this.getHeight()/2);
                    g.drawLine(this.getWidth()/2, 0,this.getWidth()/2 , this.getHeight());

                 }

    // y=c*x2 +c*x +c
     int ccx=0;
     int antcy=0;
     public void paintSQRFunc(Graphics g, double x1,double x2,int cx,int cy)
     {
         
         for(double i=x1;i<x2;i++)
         {
             //double y = Math.log(pow(i,2));
             //double xp = i+1;
             //double yp = Math.log(pow(xp,2));
             //g.drawLine((int)coord_x(i), (int)coord_y(y), (int)coord_x(xp), (int)coord_y(yp));
             g.drawLine((int)coord_x(ccx), (int)coord_y(antcy/20), (int)coord_x(ccx+10), (int)coord_y(cy/20));

         }
         ccx=ccx+10;
         antcy=cy;
     }

     private double coord_x(double x)
     {
         double real_x = x+this.getWidth()/2;
        return real_x;
     }
     private double coord_y(double y)
     {
          double real_y = -y+this.getHeight()/2;

          return (real_y);
     }
     
                        

     private static PanamaHitek_Arduino ino = new PanamaHitek_Arduino();
    private static final SerialPortEventListener listener = new SerialPortEventListener() {
        @Override
        public void serialEvent(SerialPortEvent spe) {
            try {
                if (ino.isMessageAvailable()) {
                    //Se imprime el mensaje recibido en la consola
                    String cadena=ino.printMessage();
                    System.out.println(cadena);
                    double ccyf=Double.parseDouble(cadena)*100;
                    int ccy=(int)ccyf;
                    Graficadora.plano.paintSQRFunc(Graficadora.plano.getGraphics(),-200,200,0,ccy);
                }
            } catch (SerialPortException | ArduinoException ex) {
                Logger.getLogger(Graficadora.class.getName()).log(Level.SEVERE, null, ex);
            }

        }
    };
}