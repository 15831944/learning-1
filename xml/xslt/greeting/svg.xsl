<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="xml" doctype-public="-//W3C//DTD SVG 20001102//EN" doctype-system="http://www.w3.org/TR/2000/CR-SVG-20001102/DTD/svg-20001102.dtd"></xsl:output>
  <xsl:template match="/">
   <svg width="8cm" height="4cm">
    <g>
     <defs>
      <radicalGradient id="MyGradient" cx="4cm" cy="2cm" r="3cm" fx="4cm" fy="2cm">
        <stop offset="0%" style="stop-color:red"></stop>
        <stop offset="50%" style="stop-color:blue"></stop>
        <stop offset="100%" style="stop-color:red"></stop>
      </radicalGradient>
     </defs>
     <rect style="fill:url(#MyGradient); stroke:black" x="1cm" y="1cm" width="6cm" height="2cm"></rect>
     <text x="4cm" y="2.2cm" text-anchor="middle" style="font-family:Verdana; font-size:24; font-weight:bold; fill:black">
      <xsl:apply-templates select="greeting"></xsl:apply-templates>
    </text>
   </g>
  </svg>
 </xsl:template>
 <xsl:template match="greeting">
  <xsl:value-of select="."></xsl:value-of>
 </xsl:template>
</xsl:stylesheet>
