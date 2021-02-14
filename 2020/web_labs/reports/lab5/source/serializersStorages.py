from rest_framework import serializers
from storages.models import Storage,Section
from things.models import ThingInstance
from taggit_serializer.serializers import (TagListSerializerField,
                                           TaggitSerializer)

class StorageSerializer(TaggitSerializer,serializers.ModelSerializer,):
    tags = TagListSerializerField()
    sections = serializers.PrimaryKeyRelatedField(many=True, queryset=Section.objects.all())
    owner = serializers.ReadOnlyField(source='owner.username')
    class Meta:
        model = Storage
        fields = ('id', 'name','owner','sections','tags')

class SectionSerializer(serializers.ModelSerializer):
    things_in_sections = serializers.PrimaryKeyRelatedField(many=True,queryset=ThingInstance.objects.all())
    class Meta:
        model = Section
        fields = ('id', 'name','storage','things_in_sections')