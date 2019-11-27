class Rect
{
	double l,b,ar,p;
	Rect ()
	{
		l=1;
		b=1;
	}
	// Rect(double l1,double b1)
	// {
	// 	l=l1;
	// 	b=b1;
	// }
	void set(double len,double bre)
	{
		if((len>0.0)&&(len<20.0))
		{
		  l=len;
		}
		else
		{
			System.out.println("Enter valid length and breadth:");
		}

		if((bre>0.0)&&(bre<20.0))
		{
				b=bre;
		}
		else
		{
			System.out.println("Enter valid length and breadth:");
		}
	}
	void area()
	{
		ar=l*b;
		System.out.println("AREA IS   "+ar);
	}
	void per()
	{
		p=2*(l+b);
		System.out.println("Perimeter is "+p);
	}
	void get()
	{
		System.out.println("The length is "+l+" breadth is"+b);
	}
	void dis()
	{
		System.out.println("LENGTH:"+l+"   BREADTH:"+b+"   AREA:"+ar);
	}
	
}