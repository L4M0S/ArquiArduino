package graficadora;
import java.awt.event.ActionEvent;
import javax.swing.*;
import java.awt.event.ActionListener;
import graficadora.Graficadora;

/**
 *
 * @author jorge
 */
public class Ventana extends JFrame implements ActionListener{

    @Override
    public void actionPerformed(ActionEvent e) {

       Graficadora.plano.paintSQRFunc(Graficadora.plano.getGraphics(),-200,200,0,0);
    }

}