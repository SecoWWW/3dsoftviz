#include "Git/GitEvolutionGraph.h"

#include <QDebug>
#include <QMapIterator>

Git::GitEvolutionGraph::GitEvolutionGraph() {

    // inicializacia premmenych na defaultne hodnoty
    this->getVersions() = QList<Git::GitVersion*>();
    this->filePath = "";
    this->lifespan = 0;
    this->getRemovedFiles() = QMap<QString, int>();
}

Git::GitEvolutionGraph::GitEvolutionGraph( QString filePath ) : filePath(filePath) {
    this->getVersions() = QList<Git::GitVersion*>();
    this->lifespan = 0;
    this->getRemovedFiles() = QMap<QString, int>();
}

void Git::GitEvolutionGraph::addRemovedFiles( QStringList list, int version ) {
    foreach( QString item, list ) {
        if( item != list.at( 0 ) ) {
            this->removedFiles.insert( item, version );
        }
    }
}

void Git::GitEvolutionGraph::removeRemovedFiles( QString name ) {
    this->removedFiles.remove( name );
}

void Git::GitEvolutionGraph::printRemovedFiles() {
    QMapIterator<QString, int> iter( this->removedFiles );
    while( iter.hasNext() ) {
        iter.next();
        qDebug() << iter.key() << iter.value();
    }
}
