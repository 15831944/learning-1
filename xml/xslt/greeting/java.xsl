<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
 <xsl:output method="text"></xsl:output>
 <xsl:template match="/">
  <xsl:text>
public class Greeting
{
  public static void main(String[] argv)
  {
  </xsl:text>
  <xsl:apply-templates select="greeting"></xsl:apply-templates>
  <xsl:text>
  }
}
  </xsl:text>
 </xsl:template>
 
 <xsl:template match="greeting">
  <xsl:text>System.out.println("</xsl:text>
  <xsl:value-of select="normalize-space()"></xsl:value-of>
  <xsl:text>");</xsl:text>
 </xsl:template>
</xsl:stylesheet>
