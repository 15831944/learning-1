<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
 <xsl:output method="text"/>
 <xsl:template match="/tutorial">
  <xsl:apply-templates select="section"/>
 </xsl:template>
 <xsl:template match="section">
   <xsl:text>Section </xsl:text>
   <xsl:value-of select="position()"/>
   <xsl:text>=</xsl:text>
   <xsl:value-of select="title"/>
   <xsl:text>&#xa;</xsl:text>
   <xsl:text>Even=&#xa;</xsl:text>
   <xsl:for-each select="panel">
      <xsl:if test="position() mod 2">
      	<xsl:text>Panel </xsl:text>
      	<xsl:value-of select="position()"/>
      	<xsl:text>=</xsl:text>
      	<xsl:value-of select="title"/>
      	<xsl:text>&#xa;</xsl:text>
      </xsl:if>
   </xsl:for-each>
   <xsl:text>Odds=&#xa;</xsl:text>
   <xsl:for-each select="panel">
   	  <xsl:if test="not(position() mod 2)">
      	<xsl:text>Panel </xsl:text>
      	<xsl:value-of select="position()"/>
      	<xsl:text>=</xsl:text>
      	<xsl:value-of select="title"/>
      	<xsl:text>&#xa;</xsl:text>   		
   	  </xsl:if>
   </xsl:for-each>
 </xsl:template>
</xsl:stylesheet>