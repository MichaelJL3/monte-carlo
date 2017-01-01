import java.lang.Math;
import java.util.Random;
import javax.swing.JFrame;
import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JPanel;

public class approxPiGUI extends JPanel{
    static Random rg; static Random rg2; 
    static int nn=4111;
    public static void main(String[] args){
        JFrame frame = new JFrame("Monte Carlo");
        int seed=0, height=450, width=400;
        if(args.length > 0)seed=Integer.parseInt(args[0]);
        if(args.length > 1)nn=Integer.parseInt(args[1]);
        if(seed==0)rg=new Random();
        else rg=new Random(seed);
        if(seed==0)rg2=new Random();
        else rg2=new Random(seed);
        
        approxPiGUI carlo = new approxPiGUI();
        frame.add(carlo);
        frame.setSize(width, height);
        frame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
        frame.setVisible(true);
    }
    
    public void paint(Graphics g){
        int rand=0, rand2=0, count=0;
        double pi=0;
        for(int i=0; i<=20; i++){
            g.drawLine(20*i, 0, 20*i, 400);
            g.drawLine(0, 20*i, 400, 20*i);
        }
        g.setColor(Color.blue);
        g.drawLine(0, 200, 200, 200);
        g.drawLine(0, 400, 200, 400);
        g.drawLine(0, 200, 0, 400);
        g.drawLine(200, 200, 200, 400);
        g.drawOval(0, 200, 200, 200);
        g.setColor(Color.red);
        for(int i=0; i<nn; i++){
            randx=rg.nextInt(200);
            randy=rg2.nextInt(200); 
            if(10000-Math.pow(randx-100, 2)>=Math.pow(randy-100, 2)){
		count++;
                g.setColor(Color.green);
            }
            else g.setColor(Color.red);
            randy=400-randy;
            g.drawOval(randx, randy, 1, 1);
        }
        pi=((double)count/nn)*4;
        System.out.println(pi);
    }
}
