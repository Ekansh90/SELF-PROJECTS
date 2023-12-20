SELECT * 
FROM [SQL 1]..CovidDeaths 
WHERE CONTINENT IS NOT NULL
ORDER BY 3,4 

--SELECT * 
--FROM [SQL 1].dbo.CovidVaccinations
--ORDER BY 3,4

-- .dbo.Table name ( IS SAME AS ) ..(TABLE_NAME)


-- SELECT DATA THAT WE ARE USING 
SELECT location,DATE,total_cases,new_cases,total_deaths,population
FROM [SQL 1]..CovidDeaths 
ORDER BY 1,2

-- Looking At Total Cases vs Total Deaths (TRYING TO LOOK IN "UNITED STATES" using the LIKE KEYWORD)
SELECT location,date,total_cases,total_deaths,ROUND((total_deaths/total_cases*100),1) AS PERCENTAGE_DEATHS_PER_CASES
FROM [SQL 1]..CovidDeaths 
WHERE LOCATION LIKE '%states%'
ORDER BY 1,2


-- Look at total_cases vs populdation
SELECT location,date,population,total_cases,ROUND((total_deaths/total_cases*100),1) AS PERCENTAGE_DEATHS_PER_CASES
FROM [SQL 1]..CovidDeaths 
WHERE LOCATION LIKE '%india%'
ORDER BY 1,2

-- Looking at countries with (HIGHEST Infection Rate vs Population)
SELECT LOCATION,POPULATION,MAX(total_cases) AS HIGHEST_INFEC_COUNT ,MAX((total_cases/POPULATION*100)) AS POPULATION_PERCENTAGE_INFECTED
FROM [SQL 1]..CovidDeaths 
GROUP BY LOCATION ,POPULATION
--WHERE LOCATION LIKE '%states%'
order by POPULATION_PERCENTAGE_INFECTED DESC

-- Looking at countries with (HIGHEST DEATH COUNT PER Population)
SELECT LOCATION, total_deaths 
FROM [SQL 1]..CovidDeaths
GROUP BY LOCATION , total_deaths
ORDER BY total_deaths DESC

SELECT CONTINENT ,LOCATION , POPULATION , MAX(CAST ( ( total_deaths) AS INT ) ) AS HIGHEST_NET_DEATHS,MAX((TOTAL_DEATHS)/POPULATION*100) AS DEATH_COUNT_PER_POPULATION
FROM [SQL 1]..CovidDeaths
WHERE CONTINENT IS NOT NULL
GROUP BY CONTINENT ,LOCATION,population
ORDER BY HIGHEST_NET_DEATHS DESC

SELECT CONTINENT, MAX(CAST ( ( total_deaths) AS INT ) ) AS HIGHEST_NET_DEATHS
FROM [SQL 1]..CovidDeaths
WHERE CONTINENT IS NOT NULL
GROUP BY CONTINENT --,LOCATION,population
ORDER BY HIGHEST_NET_DEATHS DESC