from rest_framework import serializers 
from things.models import Thing,ThingInstance,ThingCategory
from taggit_serializer.serializers import (TagListSerializerField,
                                           TaggitSerializer)

class ThingSerializer(TaggitSerializer, serializers.ModelSerializer):
    tags = TagListSerializerField()
    things_instances = serializers.PrimaryKeyRelatedField(many=True,queryset=ThingInstance.objects.all())
    class Meta:
        model = Thing
        fields = ('id', 'name','description','things_instances','category','tags')

class ThingInstanceSerializer(serializers.ModelSerializer):
    class Meta:
        model = ThingInstance
        fields = ('id', 'section','type','count')

class ThingCategorySerializer(serializers.ModelSerializer):
    things = serializers.PrimaryKeyRelatedField(many=True,queryset=Thing.objects.all())
    class Meta:
        model = ThingCategory
        fields = ('id', 'name','icon_label','things')