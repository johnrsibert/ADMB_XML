#include "ADMB_XMLDoc.h"
#include "admodel.h"

void init_xml_doc::allocate(const char * s)
{
   cerr << "attempting to read xml doc from file " << s << endl;
   int ret = read("xpella.xml");
   cerr << "in void init_xml_doc(void)::void allocate(const char * s), ret = "
        << ret << endl;
}

void data_int::allocate(init_xml_doc& xml, char const* s)
{
   val = xml.getInt(s);
   model_name_tag::allocate(s);
}

void data_matrix::allocate(init_xml_doc& xml, char const* s)
{
   *this = xml.getDmatrix(s);
   model_name_tag::allocate(s);
}

void param_init_bounded_number::allocate(init_xml_doc& xml, char const* s)
{
   const double minb = xml.getMinb(s);
   const double maxb = xml.getMaxb(s);
   const int phase_start = xml.getPhase(s);

   allocate(minb, maxb, phase_start, s);
   model_name_tag::allocate(s);

   // overwrite the initial value from the previous allocate
   *this  = xml.getDouble(s);
}

