<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
 <xsl:output method="xml"></xsl:output>
 <xsl:template match="/">
  <fo:root xmlns:fo="http://www.w3.org/1999/XSL/Format">
   <fo:layout-master-set>
    <fo:simple-page-master margin-right="75pt" margin-left="75pt" page-height="11in" page-width="8.5in" margin-bottom="25pt" margin-top="25pt" master-name="main">
      <fo:region-before extent="25pt"></fo:region-before>
      <fo:region-body margin-top="50pt" margin-bottom="50pt"></fo:region-body>
      <fo:region-after extent="25pt"></fo:region-after>
    </fo:simple-page-master>
    <fo:page-sequence-master master-name="standard">
     <fo:repetable-page-master-alternatives>
      <fo:conditional-page-master-reference master-name="main" odd-or-even="any"></fo:conditional-page-master-reference>
     </fo:repetable-page-master-alternatives>
    </fo:page-sequence-master>
   </fo:layout-master-set>
   
   <fo:page-sequence master-name="standard">
    <fo:flow flow-name="xsl-region-body">
     <xsl:apply-templates select="greeting"></xsl:apply-templates>
    </fo:flow>
   </fo:page-sequence>
  </fo:root>
 </xsl:template>
 
 <xsl:template match="greeting">
  <fo:block line-height="40pt" font-size="36pt" text-align="center">
   <xsl:value-of select="."></xsl:value-of>
  </fo:block>
 </xsl:template>
</xsl:stylesheet>
