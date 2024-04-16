using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        LaptopShop Ls = new LaptopShop();
        Ls.SetLaptopShop("Ronaldo.Shop");
        Ls.LoadData();
        Console.WriteLine(Ls);

        LaptopShop Ls1 = Ls.Clone();
        Ls.GetLaptops().RemoveAt(2);
        Ls1.SetLaptopShop("Messi");
        Console.WriteLine(Ls1);
    }
}

class LaptopShop : ICloneable
{
    private string laptopShop;
    private List<Laptop> laptops = new List<Laptop>();
    private Random random = new Random();

    public string GetLaptopShop()
    {
        return laptopShop;
    }
    public void SetLaptopShop(string shopName)
    {
        laptopShop = shopName;
    }
    public List<Laptop> GetLaptops()
    {
        return laptops;
    }
    public void LoadData()
    {
        for (int i = 0; i < 10; i++)
        {
            Laptop l = new Laptop();
            l.SetLap_ID(i);
            string temp = (random.Next(0, 10) > 5) ? "Ryzen" : "Intel";
            l.SetLap_processor(temp);
            laptops.Add(l);
        }
    }
    public override string ToString()
    {
        return "Shop=[Shopname=" + laptopShop + ",Laptops=" + string.Join(",", laptops) + "]";
    }
    public object Clone()
    {
        LaptopShop shop = new LaptopShop();
        shop.SetLaptopShop(laptopShop);

        foreach (Laptop l in laptops)
        {
            shop.GetLaptops().Add(l.Clone() as Laptop);
        }

        return shop;
    }
}

class Laptop : ICloneable
{
    private int Lap_ID;
    private string Lap_processor;

    public int GetLap_ID()
    {
        return Lap_ID;
    }
    public void SetLap_ID(int id)
    {
        Lap_ID = id;
    }
    public string GetLap_processor()
    {
        return Lap_processor;
    }
    public void SetLap_processor(string processor)
    {
        Lap_processor = processor;
    }

    public override string ToString()
    {
        return "{Lap_ID=" + Lap_ID + ", Lap_processor=" + Lap_processor + "}";
    }
    public object Clone()
    {
        return this.MemberwiseClone();
    }
}
