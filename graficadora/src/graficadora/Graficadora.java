package graficadora;

import javax.swing.*;
import java.awt.*;

import com.panamahitek.ArduinoException;
import com.panamahitek.PanamaHitek_Arduino;
import java.util.logging.Level;
import java.util.logging.Logger;
import jssc.SerialPortEvent;
import jssc.SerialPortEventListener;
import jssc.SerialPortException;
/**
 *
 * @author jorge
 */
public class Graficadora {

    
    //Importante, plano debe ser publico y estatico
    public static plano plano;

    public static void main(String[] args) {

        //Creando la ventana y el plano de dibujo
        Ventana frame = new Ventana();
        frame.setDefaultCloseOperation(Ventana.EXIT_ON_CLOSE);
        frame.setBounds(100, 100, 1000, 600);
        frame.setLayout(new BorderLayout());
        plano = new plano();

        //Configuración del Boton
        JButton start = new JButton("Iniciar");
        start.addActionListener(frame);
        start.setText("Iniciar");

        //Bordes al panel
        frame.add( plano, BorderLayout.CENTER);
        frame.add(start, BorderLayout.SOUTH);

        frame.setVisible( true );
        
        

    }
}