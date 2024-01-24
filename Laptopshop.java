import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class laptopshop implements Cloneable{
    Random random = new Random();
    public String laptopshop;
    List<laptop> laptops=new ArrayList<>();

    public String getLaptopshop() {
        return laptopshop;
    }
    public void setLaptopshop(String laptopshop) {
        this.laptopshop = laptopshop;
    }
    public List<laptop> getLaptops() {
        return laptops;
    }
    public void setLaptops(List<laptop> laptops) {
        this.laptops = laptops;
    }

    public void loadData(){
        for(int i=0;i<10;i++){
            laptop l=new laptop();
            l.setLap_ID(i);
            int k=random.nextInt(0,10); 
            String temp=(k>5)?"Ryzen":"Intel";
              l.setLap_processor(temp);
            getLaptops().add(l);
        }
    }
    @Override
    public String toString(){
        return "Shop=[Shopname="+laptopshop+",Laptops="+laptops+"]";
    }
     @Override
    protected laptopshop clone()throws CloneNotSupportedException{
        laptopshop shop=new laptopshop();
        
        for(laptop l: this.getLaptops()){
                shop.getLaptops().add(l);
        }

        return shop;

    }
